#include "Scene.hpp"
#include "Graphics.hpp"
#include "crust_2.hpp"
#include "random_square_2.hpp"

#include <iterator>

#include <QDebug>

Scene::Scene (QObject *parent) : QGraphicsScene(parent) {
    init();
}

void Scene::init () {
    // Points
    m_points = new QPointListItem();
    addItem(m_points);
    m_points->show();

    // Delaunay Triangulation
    m_dt = new QDelaunayTriangulationItem();
    addItem(m_dt);
    m_dt->hide();

    // Crust
    m_crust = new QSegmentListItem();
    addItem(m_crust);
    m_crust->hide();
}

void Scene::randomPointsSquare (int N, float a) {
    Points_2 points;
    random_square_2(N, a, std::back_inserter(points));
    m_points->insert(points.begin(), points.end());
    m_dt->insert(points.begin(), points.end());
    m_crust->insert(points.begin(), points.end());
}

void Scene::addPoint (int x, int y) {
    m_points->insert(Point_2(x, y));
    m_dt->insert(Point_2(x, y));
    m_crust->insert(Point_2(x, y));
}

void Scene::togglePoints () {
    if (m_points->isVisible()) {
        m_points->hide();
    } else {
        m_points->show();
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

void Scene::reset () {
    clear();

    // Re-intializes the scene
    init();
}

