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

    // Reset
    m_resetButton = new QPushButton("Reset", m_rightside);
    m_resetButton->move((m_rightside->width() - m_resetButton->width()) / 2, 0);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(m_resetButton);
    m_rightside->setLayout(layout);

    // Slots
    // Reset
    connect(m_resetButton, &QPushButton::clicked,
            this, &MainWindow::resetScene);
}

void MainWindow::resetScene () {
    m_view->m_scene->reset();
}

