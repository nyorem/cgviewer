#include <QApplication>
#include <QCheckBox>
#include <QDialog>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QInputDialog>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>
#include "Consts.hpp"
#include "MainWindow.hpp"
#include "View.hpp"

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

    // Reset
    m_resetButton = new QPushButton("Reset", m_rightside);
    m_resetButton->move((m_rightside->width() - m_resetButton->width()) / 2, 0);

    // Save
    m_saveButton = new QPushButton("Save", m_rightside);
    m_saveButton->move((m_rightside->width() - m_saveButton->width()) / 2, 0);

    // Save
    m_loadButton = new QPushButton("Load", m_rightside);
    m_loadButton->move((m_rightside->width() - m_loadButton->width()) / 2, 0);

    // Points
    m_pointsButton = new QPushButton("Points", m_rightside);
    m_pointsButton->move((m_rightside->width() - m_pointsButton->width()) / 2, 0);

    // Points in square
    m_randomSquareButton = new QPushButton("Points in square", m_rightside);
    m_randomSquareButton->move((m_rightside->width() - m_randomSquareButton->width()) / 2, 0);

    // Points on an ellipse
    m_randomEllipseButton = new QPushButton("Points on ellipse", m_rightside);
    m_randomEllipseButton->move((m_rightside->width() - m_randomEllipseButton->width()) / 2, 0);

    // Balls
    m_ballsButton = new QPushButton("Balls", m_rightside);
    m_ballsButton->move((m_rightside->width() - m_ballsButton->width()) / 2, 0);

    // Delaunay Triangulation
    m_delaunayButton = new QPushButton("Delaunay Triangulation", m_rightside);
    m_delaunayButton->move((m_rightside->width() - m_delaunayButton->width()) / 2, 0);

    // Voronoi vertices
    m_voronoiVerticesButton = new QPushButton("Voronoi vertices", m_rightside);
    m_voronoiVerticesButton->move((m_rightside->width() - m_voronoiVerticesButton->width()) / 2, 0);

    // Voronoi edges
    m_voronoiEdgesButton = new QPushButton("Voronoi edges", m_rightside);
    m_voronoiEdgesButton->move((m_rightside->width() - m_voronoiEdgesButton->width()) / 2, 0);

    // Crust
    m_crustButton = new QPushButton("Crust", m_rightside);
    m_crustButton->move((m_rightside->width() - m_crustButton->width()) / 2, 0);

    // Beta Skeleton
    m_betaSkeletonButton = new QPushButton("Beta Skeleton", m_rightside);
    m_betaSkeletonButton->move((m_rightside->width() - m_betaSkeletonButton->width()) / 2, 0);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_resetButton);
    layout->addWidget(m_saveButton);
    layout->addWidget(m_loadButton);
    layout->addWidget(m_pointsButton);
    layout->addWidget(m_randomSquareButton);
    layout->addWidget(m_randomEllipseButton);
    layout->addWidget(m_ballsButton);
    layout->addWidget(m_delaunayButton);
    layout->addWidget(m_voronoiVerticesButton);
    layout->addWidget(m_voronoiEdgesButton);
    layout->addWidget(m_crustButton);
    layout->addWidget(m_betaSkeletonButton);
    m_rightside->setLayout(layout);

    // Slots
    // Reset
    connect(m_resetButton, &QPushButton::clicked,
            this, &MainWindow::resetScene);

    // Points
    connect(m_pointsButton, &QPushButton::clicked,
            this, &MainWindow::togglePoints);

    // Save
    connect(m_saveButton, &QPushButton::clicked,
            this, &MainWindow::savePointCloud);

    // Load
    connect(m_loadButton, &QPushButton::clicked,
            this, &MainWindow::loadPointCloud);
    // Points in square
    connect(m_randomSquareButton, &QPushButton::clicked,
            this, &MainWindow::randomPointsSquare);

    // Points on ellipse
    connect(m_randomEllipseButton, &QPushButton::clicked,
            this, &MainWindow::randomPointsEllipse);

    // Balls
    connect(m_ballsButton, &QPushButton::clicked,
            this, &MainWindow::toggleBalls);

    // Delaunay Triangulation
    connect(m_delaunayButton, &QPushButton::clicked,
            this, &MainWindow::toggleDelaunayTriangulation);

    // Voronoi vertices
    connect(m_voronoiVerticesButton, &QPushButton::clicked,
            this, &MainWindow::toggleVoronoiVertices);

    // Voronoi vertices
    connect(m_voronoiEdgesButton, &QPushButton::clicked,
            this, &MainWindow::toggleVoronoiEdges);

    // Crust
    connect(m_crustButton, &QPushButton::clicked,
            this, &MainWindow::toggleCrust);

    // Beta Skeleton
    connect(m_betaSkeletonButton, &QPushButton::clicked,
            this, &MainWindow::toggleBetaSkeleton);

    // Parameters initialization
    // Ball radius
    double radius = QInputDialog::getDouble(this, "Parameters for balls", "Radius",
                                            15.0, 0, 200);
    m_view->m_scene->setBallRadius(radius);
}

// Events
void MainWindow::resizeEvent (QResizeEvent* event) {
    int w = event->size().width(),
        h = event->size().height();

    resize(w, h);
    m_view->resize(w - 200, h);

    m_rightside->move(w - 200, 0);
    m_rightside->resize(200, h);
}

// Slots
void MainWindow::resetScene () {
    m_view->m_scene->reset();
}

void MainWindow::savePointCloud () {
    m_view->m_scene->savePointCloud();
}

void MainWindow::loadPointCloud () {
    m_view->m_scene->loadPointCloud();
}

void MainWindow::togglePoints () {
    m_view->m_scene->togglePoints();
}

void MainWindow::randomPointsSquare () {
    QDialog dialog(this);
    dialog.setWindowTitle("Parameters");
    QFormLayout formLayout(&dialog);

    QSpinBox *numberPoints = new QSpinBox();
    numberPoints->setMinimum(1);
    numberPoints->setMaximum(100000);
    numberPoints->setSingleStep(10);
    numberPoints->setValue(100);
    formLayout.addRow("Number of points:", numberPoints);

    QDoubleSpinBox *radiusSquare = new QDoubleSpinBox();
    radiusSquare->setMinimum(1);
    radiusSquare->setMaximum(100);
    radiusSquare->setSingleStep(0.1);
    radiusSquare->setValue(1);
    formLayout.addRow("Radius:", radiusSquare);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    formLayout.addRow(&buttonBox);

    connect(&buttonBox, &QDialogButtonBox::accepted,
            &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected,
            &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        m_view->m_scene->randomPointsSquare(numberPoints->value(),
                                            radiusSquare->value() * 100);
    }
}

void MainWindow::randomPointsEllipse () {
    QDialog dialog(this);
    dialog.setWindowTitle("Parameters");
    QFormLayout formLayout(&dialog);

    QSpinBox *numberPoints = new QSpinBox();
    numberPoints->setMinimum(1);
    numberPoints->setMaximum(100000);
    numberPoints->setSingleStep(10);
    numberPoints->setValue(100);
    formLayout.addRow("Number of points:", numberPoints);

    QDoubleSpinBox *majorAxis = new QDoubleSpinBox();
    majorAxis->setMinimum(0.5);
    majorAxis->setMaximum(100);
    majorAxis->setSingleStep(0.1);
    majorAxis->setValue(1.5);

    QDoubleSpinBox *minorAxis = new QDoubleSpinBox();
    minorAxis->setMinimum(0.5);
    minorAxis->setMaximum(100);
    minorAxis->setSingleStep(0.1);
    minorAxis->setValue(1);

    QDoubleSpinBox *noiseVariance = new QDoubleSpinBox();
    noiseVariance->setMinimum(0);
    noiseVariance->setMaximum(200);
    noiseVariance->setSingleStep(1);
    noiseVariance->setValue(0);

    QDoubleSpinBox *oscMagnitude = new QDoubleSpinBox();
    oscMagnitude->setMinimum(0);
    oscMagnitude->setMaximum(200);
    oscMagnitude->setSingleStep(5);
    oscMagnitude->setValue(0);

    QCheckBox *uniform = new QCheckBox("Uniform");
    uniform->setChecked(true);

    formLayout.addRow("Major axis:", majorAxis);
    formLayout.addRow("Minor axis:", minorAxis);
    formLayout.addRow("Noise variance:", noiseVariance);
    formLayout.addRow("Oscillation magnitude", oscMagnitude);
    formLayout.addRow(uniform);

    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
                               Qt::Horizontal, &dialog);
    formLayout.addRow(&buttonBox);

    connect(&buttonBox, &QDialogButtonBox::accepted,
            &dialog, &QDialog::accept);
    connect(&buttonBox, &QDialogButtonBox::rejected,
            &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        m_view->m_scene->randomPointsEllipse(numberPoints->value(),
                                             majorAxis->value() * 120,
                                             minorAxis->value() * 120,
                                             noiseVariance->value() * 10,
                                             oscMagnitude->value(),
                                             uniform->isChecked());
    }
}

void MainWindow::toggleBalls () {
    m_view->m_scene->toggleBalls();
}

void MainWindow::toggleDelaunayTriangulation () {
    m_view->m_scene->toggleDelaunayTriangulation();
}

void MainWindow::toggleVoronoiVertices () {
    m_view->m_scene->toggleVoronoiVertices();
}

void MainWindow::toggleVoronoiEdges () {
    m_view->m_scene->toggleVoronoiEdges();
}

void MainWindow::toggleCrust () {
    m_view->m_scene->toggleCrust();
}

void MainWindow::toggleBetaSkeleton () {
    m_view->m_scene->toggleBetaSkeleton();
}

