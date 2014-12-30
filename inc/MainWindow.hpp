#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include <QWidget>
#include <QPushButton>

#include "Consts.hpp"
#include "View.hpp"

class MainWindow : public QWidget {
    Q_OBJECT

    public:
        MainWindow (int w = consts::width_window,
                    int h = consts::height_window);

    public slots:
        void resetScene ();

    private:
        View *m_view;
        QWidget *m_rightside;
        QPushButton *m_resetButton;
};

#endif

