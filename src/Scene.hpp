#ifndef _PAINTER_HPP_
#define _PAINTER_HPP_

#include <QObject>
#include <QGraphicsScene>

#include "CGAL_typedefs.hpp"
#include "QPointListItem.hpp"
#include "QCrustItem.hpp"

class Scene : public QGraphicsScene {
    public:
        Scene (QObject *parent = 0);
        void init ();

        void addPoint (int x, int y);

        void togglePoints ();
        void toggleDelaunayTriangulation ();
        void toggleVoronoiVertices ();
        void toggleCrust ();
        void randomPointsSquare (int N, float a);

        void reset ();

    private:
        QPointListItem* m_points;
        QCrustItem* m_crust;
        QDelaunayTriangulation2Item* m_dt;
};

#endif

