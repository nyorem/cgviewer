#ifndef _QSEGMENTLISTITEM_HPP_
#define _QSEGMENTLISTITEM_HPP_

#include <QGraphicsItem>
#include <QPainter>

#include <CGAL/Bbox_2.h>

#include "CGAL_typedefs.hpp"
#include "Graphics.hpp"
#include "crust_2.hpp"

// TODO: make class generic (not use crust_2)
class QSegmentListItem : public QGraphicsItem {
    public:
        QSegmentListItem (QGraphicsItem *parent = 0) : QGraphicsItem(parent) {}

        void insert (Point_2 p) {
            m_points.push_back(p);

            m_crust.clear();
            crust_2(m_points.begin(), m_points.end(),
                    std::back_inserter(m_crust));
        }

        template <typename InputIterator>
        void insert (InputIterator begin,
                     InputIterator beyond) {
            m_points.insert(m_points.begin(), begin, beyond);

            m_crust.clear();
            crust_2(m_points.begin(), m_points.end(),
                    std::back_inserter(m_crust));
        }

        void paint (QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget) {
            // FIXME: pass color as a parameter
            painter->setPen(Graphics::solidGreen);

            for (int i = 0; i < m_crust.size(); ++i) {
                Segment_2 s = m_crust[i];
                Point_2 p = s.source(), q = s.target();
                painter->drawLine(p.x(), p.y(), q.x(), q.y());
            }

            QGraphicsItem::scene()->update();
        }

        QRectF boundingRect () const {
            CGAL::Bbox_2 b = CGAL::bbox_2(m_points.begin(), m_points.end());

            QPointF topLeft(b.xmin(), b.ymax()),
                    bottomRight(b.xmax(), b.ymin());

            return QRectF(topLeft, bottomRight);
        }

        ~QSegmentListItem () {
            m_points.clear();
        }

    private:
        Points_2 m_points;
        Segments_2 m_crust;
};

#endif

