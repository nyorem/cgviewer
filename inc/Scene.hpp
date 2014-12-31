#ifndef _PAINTER_HPP_
#define _PAINTER_HPP_

#include <QObject>
#include <QGraphicsScene>

#include "QPointListItem.hpp"
#include "QTriangulationItem.hpp"
#include "QSegmentListItem.hpp"

class Scene : public QGraphicsScene {
    public:
        Scene (QObject *parent = 0);
        void init ();

        void addPoint (int x, int y);

        void togglePoints ();
        void toggleDelaunayTriangulation ();
        void toggleCrust ();
        void randomPointsSquare (int N, float a);

        void reset ();

    private:
        QPointListItem* m_points;
        QSegmentListItem* m_crust;
        QDelaunayTriangulationItem* m_dt;
};

#endif

