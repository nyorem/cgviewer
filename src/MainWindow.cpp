#include "MainWindow.hpp"
#include "View.hpp"
#include "Consts.hpp"

#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow (int w, int h) : QWidget() {
    resize(w, h);
    setWindowTitle("CGViewer");

    // Left side: view
    m_view = new View(consts::width_view, consts::height_view, this);

    // Right side: buttons
    m_rightside = new QWidget(this);
    m_rightside->move(consts::width_view, 0);
    m_rightside->resize(consts::width_window - consts::width_view,
                        consts::height_window);

    // Points
    m_pointsButton = new QPushButton("Points", m_rightside);
    m_pointsButton->move((m_rightside->width() - m_pointsButton->width()) / 2, 0);

    // Reset
    m_resetButton = new QPushButton("Reset", m_rightside);
    m_resetButton->move((m_rightside->width() - m_resetButton->width()) / 2, 0);

    // Delaunay Triangulation
    m_delaunayButton = new QPushButton("Delaunay Triangulation", m_rightside);
    m_delaunayButton->move((m_rightside->width() - m_delaunayButton->width()) / 2, 0);

    // Delaunay Triangulation
    m_voronoiVerticesButton = new QPushButton("Voronoi vertices", m_rightside);
    m_voronoiVerticesButton->move((m_rightside->width() - m_voronoiVerticesButton->width()) / 2, 0);

    // Crust
    m_crustButton = new QPushButton("Crust", m_rightside);
    m_crustButton->move((m_rightside->width() - m_crustButton->width()) / 2, 0);

    // Points in square
    m_randomSquareButton = new QPushButton("Points in square", m_rightside);
    m_randomSquareButton->move((m_rightside->width() - m_randomSquareButton->width()) / 2, 0);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_pointsButton);
    layout->addWidget(m_resetButton);
    layout->addWidget(m_delaunayButton);
    layout->addWidget(m_voronoiVerticesButton);
    layout->addWidget(m_crustButton);
    layout->addWidget(m_randomSquareButton);
    m_rightside->setLayout(layout);

    // Slots
    // Points
    connect(m_pointsButton, &QPushButton::clicked,
            this, &MainWindow::togglePoints);

    // Reset
    connect(m_resetButton, &QPushButton::clicked,
            this, &MainWindow::resetScene);

    // Delaunay Triangulation
    connect(m_delaunayButton, &QPushButton::clicked,
            this, &MainWindow::toggleDelaunayTriangulation);

    // Voronoi vertices
    connect(m_voronoiVerticesButton, &QPushButton::clicked,
            this, &MainWindow::toggleVoronoiVertices);

    // Crust
    connect(m_crustButton, &QPushButton::clicked,
            this, &MainWindow::toggleCrust);

    // Points in square
    connect(m_randomSquareButton, &QPushButton::clicked,
            this, &MainWindow::randomPointsSquare);
}

// Slots
void MainWindow::togglePoints () {
    m_view->m_scene->togglePoints();
}

void MainWindow::resetScene () {
    m_view->m_scene->reset();
}

void MainWindow::toggleDelaunayTriangulation () {
    m_view->m_scene->toggleDelaunayTriangulation();
}

void MainWindow::toggleVoronoiVertices () {
    m_view->m_scene->toggleVoronoiVertices();
}

void MainWindow::toggleCrust () {
    m_view->m_scene->toggleCrust();
}

void MainWindow::randomPointsSquare () {
    // TODO: add slider for radius
    m_view->m_scene->randomPointsSquare(100, 150);
}

