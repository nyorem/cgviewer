#ifndef _VIEW_HPP_
#define _VIEW_HPP_

#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWidget>
#include "Scene.hpp"

class View : public QGraphicsView {
    public:
        View (int w, int h, QWidget *parent = 0);

        void mousePressEvent (QMouseEvent *event);
        void keyPressEvent (QKeyEvent *event);

        Scene *m_scene;
};

#endif

