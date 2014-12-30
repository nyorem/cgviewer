#ifndef _CRUST_2_H_
#define _CRUST_2_H_

#include "CGAL_typedefs.hpp"

#include <CGAL/Delaunay_triangulation_2.h>

// Computes the crust of a list of points
// Pre-condition:
// -> InputIterator::value_type = Point_2
// -> OutputIterator::value_type = Segment_2
template <typename InputIterator,
          typename OutputIterator>
void crust_2 (InputIterator begin,
              InputIterator beyond,
              OutputIterator out) {
    typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay_triangulation_2;
    typedef Delaunay_triangulation_2::Face_handle Face_handle;

    Points_2 points_V, points_Sprime;

    // Initialization
    points_Sprime.insert(points_Sprime.begin(), begin, beyond);

    // Computes Voronoi vertices
    Delaunay_triangulation_2 dt(begin, beyond);
    for (Delaunay_triangulation_2::Finite_faces_iterator fit = dt.finite_faces_begin();
         fit != dt.finite_faces_end();
         ++fit) {
        Face_handle handle = fit;
        Point_2 p = dt.dual(handle);
        points_V.push_back(p);
        points_Sprime.push_back(p);
    }

    // Computes crust
    Delaunay_triangulation_2 dtt(points_Sprime.begin(), points_Sprime.end());
    for (Delaunay_triangulation_2::Finite_edges_iterator eit = dtt.finite_edges_begin();
         eit != dtt.finite_edges_end();
         ++eit) {
        Segment_2 s = dtt.segment(*eit);
        if ( (std::find(begin, beyond, s.source()) != beyond) &&
             (std::find(begin, beyond, s.target()) != beyond) ) {
            *(out++) = s;
        }
    }
}

#endif

