#include "Scene.hpp"
#include "Graphics.hpp"
#include "crust_2.hpp"
#include "random_square_2.hpp"

#include <iterator>

#include <QDebug>

Scene::Scene (QObject *parent) : QGraphicsScene(parent) {
}

void Scene::randomPointsSquare (int N, float a){
    random_square_2(N, a, std::back_inserter(m_points));
    for (int i = 0; i < m_points.size(); ++i) {
        addEllipse(m_points[i].x(), m_points[i].y(), 1, 1);
    }
}

void Scene::addPoint (int x, int y) {
    m_points.push_back(Point_2(x, y));
    addEllipse(x, y, 1, 1);
}

void Scene::compute_crust () {
    crust_2(m_points.begin(), m_points.end(),
            std::back_inserter(m_crust));
}

void Scene::addCrust () {
    for (int i = 0; i < m_crust.size(); ++i) {
        Segment_2 s = m_crust[i];
        Point_2 p = s.source(), q = s.target();
        addLine(p.x(), p.y(), q.x(), q.y(), Graphics::solidRed);
    }
}

void Scene::addDelaunayTriangulation () {
    dt.clear();
    dt.insert(m_points.begin(), m_points.end());
    for (Delaunay_triangulation_2::Finite_edges_iterator eit = dt.finite_edges_begin();
         eit != dt.finite_edges_end();
         ++eit) {
        Segment_2 s = dt.segment(*eit);
        Point_2 p = s.source(), q = s.target();
        addLine(p.x(), p.y(), q.x(), q.y(), Graphics::solidRed);
    }
}

void Scene::reset () {
    m_points.clear();
    m_crust.clear();
    dt.clear();
    clear();
}

