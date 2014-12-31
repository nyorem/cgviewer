#ifndef _MAINWINDOW_HPP_
#define _MAINWINDOW_HPP_

#include <QPushButton>
#include <QWidget>

#include "Consts.hpp"
#include "View.hpp"

class MainWindow : public QWidget {
    Q_OBJECT

    public:
        MainWindow (int w = consts::width_window,
                    int h = consts::height_window);

    public slots:
        void togglePoints ();
        void resetScene ();
        void toggleDelaunayTriangulation ();
        void toggleCrust ();
        void randomPointsSquare ();

    private:
        View *m_view;
        QWidget *m_rightside;

        QPushButton* m_pointsButton;
        QPushButton* m_resetButton;
        QPushButton* m_delaunayButton;
        QPushButton* m_crustButton;
        QPushButton* m_randomSquareButton;
};

#endif

