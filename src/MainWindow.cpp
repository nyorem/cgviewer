#include "MainWindow.hpp"
#include "Scene.hpp"

#include <QApplication>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>

#include <QDebug>

MainWindow::MainWindow (int w, int h) : QGraphicsView() {
    resize(w, h);
    setWindowTitle("Crust");

    m_scene = new Scene();
    setScene(m_scene);
}

void MainWindow::mousePressEvent (QMouseEvent *event) {
    // Initial origin: center of the view
    // mapToScene transforms the coordinates accordingly
    QPointF point = mapToScene(event->pos());
    m_scene->addPoint(point.x(), point.y());
}

void MainWindow::keyPressEvent (QKeyEvent *event) {
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

