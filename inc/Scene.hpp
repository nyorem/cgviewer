#ifndef _PAINTER_HPP_
#define _PAINTER_HPP_

#include <QObject>
#include <QGraphicsScene>

#include "CGAL_typedefs.hpp"

class Scene : public QGraphicsScene {
    public:
        Scene (QObject *parent = 0);

        void randomPointsSquare (int N, float a);

        void addPoint (int x, int y);

        void compute_crust ();
        void addCrust ();

        void addDelaunayTriangulation ();

        void reset ();

    private:
        Points_2 m_points;
        Segments_2 m_crust;
        Delaunay_triangulation_2 dt;
};

#endif

