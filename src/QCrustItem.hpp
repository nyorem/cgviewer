#ifndef _QCRUSTITEM_HPP_
#define _QCRUSTITEM_HPP_

#include "QSegmentListItem.hpp"
#include "crust_2.hpp"

// Wrapper for computing and displaying the crust of a list of points
class QCrustItem : public QSegmentListItem {
    public:
        QCrustItem (const QPen& pen,
                    QGraphicsItem *parent = 0) : QSegmentListItem(pen, parent) {}

    protected:
        void computeSegments () {
            m_segments.clear();
            crust_2(m_points.begin(), m_points.end(),
                    std::back_inserter(m_segments));
        }

};

#endif

