#include "Scene.hpp"
#include "Graphics.hpp"
#include "crust_2.hpp"
#include "random_square_2.hpp"

#include <iterator>

Scene::Scene (QObject *parent) : QGraphicsScene(parent) {
    init();
}

void Scene::init () {
    // Points
    m_points = new QPointListItem(Graphics::solidBlack);
    addItem(m_points);
    m_points->show();

    // Delaunay Triangulation and Voronoi vertices
    m_dt = new QDelaunayTriangulation2Item(Graphics::solidRed, Graphics::solidBlue);
    addItem(m_dt);
    m_dt->hide();

    // Balls (offset)
    m_balls = new QPointListItem(Graphics::solidRed);
    addItem(m_balls);
    m_balls->hide();

    // Regular Triangulation
    m_rt = new QRegularTriangulation2Item(Graphics::solidPurple);
    addItem(m_rt);
    m_rt->hide();

    // Crust
    m_crust = new QCrustItem(Graphics::solidGreen);
    addItem(m_crust);
    m_crust->hide();
}

void Scene::addPoint (int x, int y) {
    m_points->insert(Point_2(x, y));
    m_dt->insert(Point_2(x, y));
    m_crust->insert(Point_2(x, y));
    m_balls->insert(Point_2(x, y));
    m_rt->insert(Point_2(x, y), m_balls->radius());
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

void Scene::toggleDelaunayTriangulation () {
    if (m_dt->isVisible()) {
        m_dt->hide();
    } else {
        m_dt->show();
        update();
    }
}

void Scene::toggleRegularTriangulation () {
    if (m_rt->isVisible()) {
        m_rt->hide();
    } else {
        m_rt->show();
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

void Scene::randomPointsSquare (int N, float a) {
    Points_2 points;
    random_square_2(N, a, std::back_inserter(points));
    m_points->insert(points.begin(), points.end());
    m_dt->insert(points.begin(), points.end());
    m_crust->insert(points.begin(), points.end());
    m_rt->insert(points.begin(), points.end(), m_balls->radius());
}

void Scene::reset () {
    clear();

    // Re-intializes the scene
    init();
}

