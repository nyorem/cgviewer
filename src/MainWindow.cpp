#include "MainWindow.hpp"
#include "View.hpp"
#include "Consts.hpp"

#include <QApplication>

#include <QDebug>

MainWindow::MainWindow (int w, int h) : QWidget() {
    resize(w, h);
    setWindowTitle("CGViewer");

    m_view = new View(consts::width_view, consts::height_view, this);
}

