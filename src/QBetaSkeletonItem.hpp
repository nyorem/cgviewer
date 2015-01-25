#ifndef _QBETASKELETONITEM_HPP_
#define _QBETASKELETONITEM_HPP_

#include "QSegmentListItem.hpp"
#include "beta_skeleton_2.hpp"

// Wrapper for computing and displaying the beta skeleton of a list of points
class QBetaSkeletonItem : public QSegmentListItem {
    public:
        QBetaSkeletonItem (double beta,
                           const QPen& pen,
                           QGraphicsItem *parent = 0) : QSegmentListItem(pen, parent),
                                                        m_beta(beta) {}

    protected:
        void computeSegments () {
            m_segments.clear();
            beta_skeleton_2(m_points.begin(), m_points.end(), m_beta,
                            std::back_inserter(m_segments));
        }

    private:
        double m_beta;

};

#endif

