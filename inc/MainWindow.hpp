#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include "Scene.hpp"

#include <QGraphicsView>
#include <QMouseEvent>
#include <QKeyEvent>

#define WIDTH 800
#define HEIGHT 600

class MainWindow : public QGraphicsView {
    public:
        MainWindow (int w = WIDTH, int h = HEIGHT);

        void mousePressEvent (QMouseEvent *event);
        void keyPressEvent (QKeyEvent *event);

    private:
        Scene *m_scene;
};

#endif

