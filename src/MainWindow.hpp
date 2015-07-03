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

        // Events
        void resizeEvent (QResizeEvent* event);

    public slots:
        void resetScene ();
        void savePointCloud ();
        void loadPointCloud ();
        void togglePoints ();
        void randomPointsSquare ();
        void randomPointsEllipse ();
        void toggleBalls ();
        void toggleDelaunayTriangulation ();
        void toggleVoronoiVertices ();
        void toggleVoronoiEdges ();
        void toggleCrust ();
        void toggleBetaSkeleton ();

    private:
        View *m_view;
        QWidget *m_rightside;

        QPushButton *m_resetButton,
                    *m_saveButton,
                    *m_loadButton,
                    *m_pointsButton,
                    *m_ballsButton,
                    *m_delaunayButton,
                    *m_voronoiVerticesButton,
                    *m_voronoiEdgesButton,
                    *m_crustButton,
                    *m_betaSkeletonButton,
                    *m_randomEllipseButton,
                    *m_randomSquareButton;
};

#endif

