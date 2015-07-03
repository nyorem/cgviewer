#include <fstream>
#include <iterator>
#include <QFileDialog>
#include "Graphics.hpp"
#include "random_square_2.hpp"
#include "random_ellipse_2.hpp"
#include "Scene.hpp"

Scene::Scene (QObject *parent) : QGraphicsScene(parent) {
    init();
}

void Scene::init () {
    // Points
    m_points = new QPointListItem(Graphics::solidBlack);
    addItem(m_points);
    m_points->show();

    // Delaunay Triangulation and Voronoi vertices
    m_dt = new QDelaunayTriangulation2Item(Graphics::solidBlack, Graphics::solidPurple);
    addItem(m_dt);
    m_dt->hide();

    // Balls (offset)
    m_balls = new QPointListItem(Graphics::solidRed, true);
    addItem(m_balls);
    m_balls->hide();

    // Crust
    m_crust = new QCrustItem(Graphics::solidBlack);
    addItem(m_crust);
    m_crust->hide();

    // Beta Skeleton
    // TODO: beta dialog box
    m_betaSkeleton = new QBetaSkeletonItem(1.7, Graphics::solidGreen);
    addItem(m_betaSkeleton);
    m_betaSkeleton->hide();
}

void Scene::addPoint (int x, int y) {
    m_points->insert(Point_2(x, y));
    m_dt->insert(Point_2(x, y));
    m_balls->insert(Point_2(x, y));

    m_crust->insert(Point_2(x, y));
    m_betaSkeleton->insert(Point_2(x, y));
}

void Scene::setBallRadius (float radius) {
    m_balls->setRadius(radius);
}

void Scene::togglePoints () {
    if (m_points->isVisible()) {
        m_points->hide();
    } else {
        m_points->show();
        update();
    }
}

void Scene::toggleBalls () {
    if (m_balls->isVisible()) {
        m_balls->hide();
    } else {
        m_balls->show();
        update();
    }
}

void Scene::toggleCrust () {
    if (m_crust->isVisible()) {
        m_crust->hide();
    } else {
        m_crust->show();
        update();
    }
}

void Scene::toggleBetaSkeleton () {
    if (m_betaSkeleton->isVisible()) {
        m_betaSkeleton->hide();
    } else {
        m_betaSkeleton->show();
        update();
    }
}

void Scene::toggleDelaunayTriangulation () {
    if (m_dt->isVisible()) {
        m_dt->hide();
    } else {
        m_dt->show();
        update();
    }
}

void Scene::toggleVoronoiVertices () {
    if (m_dt->isVoronoiVerticesVisible()) {
        m_dt->hideVoronoiVertices();
    } else {
        m_dt->showVoronoiVertices();
        update();
    }
}

void Scene::toggleVoronoiEdges () {
    if (m_dt->isVoronoiEdgesVisible()) {
        m_dt->hideVoronoiEdges();
    } else {
        m_dt->showVoronoiEdges();
        update();
    }
}

void Scene::randomPointsSquare (int N, float a) {
    Points_2 points;
    random_square_2(N, a, std::back_inserter(points));
    m_points->insert(points.begin(), points.end());
    m_dt->insert(points.begin(), points.end());

    m_crust->insert(points.begin(), points.end());
    m_betaSkeleton->insert(points.begin(), points.end());
}

void Scene::randomPointsEllipse (int N, float a, float b,
                                 float noiseVariance,
                                 float oscMagnitude,
                                 bool uniform) {
    Points_2 points;
    random_on_ellipse_2(N, a, b, noiseVariance, oscMagnitude, uniform,
                        std::back_inserter(points));

    m_points->insert(points.begin(), points.end());
    m_balls->insert(points.begin(), points.end());
    m_dt->insert(points.begin(), points.end());

    m_crust->insert(points.begin(), points.end());
    m_betaSkeleton->insert(points.begin(), points.end());
}

void Scene::savePointCloud () {
    QString filename = QFileDialog::getSaveFileName(0, tr("Save Point Cloud"),
                                                    QDir::currentPath(),
                                                    tr("Point Clouds (*.xy)"));

    std::ofstream file(filename.toStdString().c_str());

    for (std::vector<Point_2>::iterator it = m_points->begin();
         it != m_points->end();
         ++it) {
        Point_2& p = *it;
        file << p.x() << " " << p.y() << std::endl;
    }
}

void Scene::loadPointCloud () {
    QString filename = QFileDialog::getOpenFileName(0, tr("Open Point Cloud"),
                                                    QDir::currentPath(),
                                                    tr("Point Clouds (*.xy)"));

    std::vector<Point_2> points;
    std::ifstream file(filename.toStdString().c_str());

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        float x, y;
        if (ss >> x >> y) {
            Point_2 p(x, y);
            points.push_back(p);
        }
    }

    // Update
    m_points->insert(points.begin(), points.end());

    m_balls->clear();
    m_balls->insert(m_points->begin(), m_points->end());

    m_dt->clear();
    m_dt->insert(m_points->begin(), m_points->end());
}

void Scene::reset () {
    clear();

    // Re-intializes the scene
    init();
}

