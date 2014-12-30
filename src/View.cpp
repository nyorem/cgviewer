#include "View.hpp"
#include "Scene.hpp"

#include <QApplication>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QDebug>

View::View (int w, int h, QWidget *parent) : QGraphicsView(parent) {
    resize(w, h);

    m_scene = new Scene();
    setScene(m_scene);
}

void View::mousePressEvent (QMouseEvent *event) {
    // Initial origin: center of the view
    // mapToScene transforms the coordinates accordingly
    QPointF point = mapToScene(event->pos());
    m_scene->addPoint(point.x(), point.y());
}

void View::keyPressEvent (QKeyEvent *event) {
    switch (event->key()) {
        case Qt::Key_A:
            m_scene->randomPointsSquare(100, 150);
            break;

        case Qt::Key_C:
            m_scene->compute_crust();
            m_scene->addCrust();
            break;

        case Qt::Key_T:
            m_scene->addDelaunayTriangulation();
            break;

        case Qt::Key_R:
            m_scene->reset();
            break;

        case Qt::Key_Escape:
            qApp->quit();
            break;

        default:
            break;
    }
}

