#ifndef _PAINTER_HPP_
#define _PAINTER_HPP_

#include <QGraphicsScene>
#include <QObject>
#include "CGAL_typedefs.hpp"
#include "QBetaSkeletonItem.hpp"
#include "QCrustItem.hpp"
#include "QPointListItem.hpp"

class Scene : public QGraphicsScene {
    public:
        Scene (QObject *parent = 0);

        void init ();
        void addPoint (int x, int y);
        void setBallRadius (float radius);
        void reset ();

        void togglePoints ();
        void toggleBalls ();
        void toggleDelaunayTriangulation ();
        void toggleVoronoiVertices ();
        void toggleVoronoiEdges ();
        void toggleCrust ();

        void toggleBetaSkeleton ();
        void randomPointsSquare (int N, float a);
        void randomPointsEllipse (int N, float a, float b,
                                  float noiseVariance,
                                  float oscMagnitude, bool uniform);

        void savePointCloud ();
        void loadPointCloud ();

    private:
        QPointListItem* m_points;
        QPointListItem* m_balls;
        QCrustItem* m_crust;
        QBetaSkeletonItem* m_betaSkeleton;
        QDelaunayTriangulation2Item* m_dt;
};

#endif

