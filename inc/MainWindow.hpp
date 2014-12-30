#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include <QWidget>

#include "Consts.hpp"
#include "View.hpp"

class MainWindow : public QWidget {
    public:
        MainWindow (int w = consts::width_window,
                    int h = consts::height_window);

    private:
        View *m_view;
};

#endif

