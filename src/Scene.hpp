#ifndef _PAINTER_HPP_
#define _PAINTER_HPP_

#include <QObject>
#include <QGraphicsScene>

#include "CGAL_typedefs.hpp"
#include "QPointListItem.hpp"
#include "QBetaSkeletonItem.hpp"
#include "QCrustItem.hpp"

class Scene : public QGraphicsScene {
    public:
        Scene (QObject *parent = 0);

        void init ();

        void addPoint (int x, int y);

        void setBallRadius (float radius);

        void togglePoints ();
        void toggleBalls ();
        void toggleDelaunayTriangulation ();
        void toggleRegularTriangulation ();
        void toggleVoronoiVertices ();
        void toggleCrust ();
        void toggleBetaSkeleton ();
        void randomPointsSquare (int N, float a);

        void reset ();

    private:
        QPointListItem* m_points;
        QPointListItem* m_balls;
        QCrustItem* m_crust;
        QBetaSkeletonItem* m_betaSkeleton;
        QDelaunayTriangulation2Item* m_dt;
        QRegularTriangulation2Item* m_rt;
};

#endif

