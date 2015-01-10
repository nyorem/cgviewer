#ifndef _QPOINTLISTITEM_HPP_
#define _QPOINTLISTITEM_HPP_

#include <QGraphicsItem>
#include <QPainter>

#include <CGAL/Bbox_2.h>

#include "CGAL_typedefs.hpp"

// Wrapper for displaying a list of points
class QPointListItem : public QGraphicsItem {
    public:
        QPointListItem (const QPen& pen,
                        float radius = 1.0,
                        QGraphicsItem *parent = 0) : QGraphicsItem(parent), m_radius(radius), pen(pen) {}

        void insert (Point_2 p) {
            m_points.push_back(p);
        }

        template <typename InputIterator>
        void insert (InputIterator begin,
                     InputIterator beyond) {
            m_points.insert(m_points.begin(), begin, beyond);
        }

        void setRadius (float radius) {
            m_radius = radius;
        }

        float radius () const {
            return m_radius;
        }

        void paint (QPainter *painter,
                    const QStyleOptionGraphicsItem *option,
                    QWidget *widget) {
            painter->setPen(pen);

            for (int i = 0; i < m_points.size(); ++i) {
                painter->drawEllipse(QPointF(m_points[i].x(), m_points[i].y()),
                                     m_radius, m_radius);
            }

            QGraphicsItem::scene()->update();
        }

        QRectF boundingRect () const {
            CGAL::Bbox_2 b = CGAL::bbox_2(m_points.begin(), m_points.end());

            QPointF topLeft(b.xmin(), b.ymax()),
                    bottomRight(b.xmax(), b.ymin());

            return QRectF(topLeft, bottomRight);
        }

        ~QPointListItem () {
            m_points.clear();
        }

    private:
        Points_2 m_points;
        float m_radius;
        QPen pen;
};

#endif

