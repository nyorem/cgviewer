#ifndef _BETA_SKELETON_2_H_
#define _BETA_SKELETON_2_H_

#include "CGAL_typedefs.hpp"

#include <CGAL/Delaunay_triangulation_2.h>

// Computes the beta skeleton of a list of points.
// Pre-conditions:
// -> InputIterator::value_type = Point_2
// -> OutputIterator::value_type = Segment_2
template <typename InputIterator,
          typename OutputIterator>
void beta_skeleton_2 (InputIterator begin,
                      InputIterator beyond,
                      double beta,
                      OutputIterator out) {
    typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay_triangulation_2;
    typedef Delaunay_triangulation_2::Face_handle Face_handle;

    Delaunay_triangulation_2 dt(begin, beyond);

    if (dt.number_of_vertices() <= 3) {
        return;
    }

    for (Delaunay_triangulation_2::Finite_edges_iterator eit = dt.finite_edges_begin();
         eit != dt.finite_edges_end();
         ++eit) {
        Segment_2 s = dt.segment(*eit);
        Line_2 edge(s);

        // Adjacent faces
        Face_handle f = eit->first,
                    ff = eit->first->neighbor(eit->second);

        // Convert the faces to triangles
        Triangle_2 t = dt.triangle(f),
                   tt = dt.triangle(ff);

        // Circumcenters
        Point_2 p = CGAL::circumcenter(t),
                pp = CGAL::circumcenter(tt);

        // Radius of the circumcircles
        FT r = CGAL::squared_distance(p, t[0]),
           rr = CGAL::squared_distance(pp, tt[0]);

        // Length of the edge
        FT len = s.squared_length();

        // If one face is infinite, then we only check
        // if the condition on the radii is verified.
        // If none of the faces are infinite, then we also
        // check that the circumcenters are on opposite sides
        // of the edge.
        if ( (dt.is_infinite(f) && rr > 0.25 * beta * beta * len)
          || (dt.is_infinite(ff) && r > 0.25 * beta * beta * len)
          || (edge.oriented_side(p) != edge.oriented_side(pp) && (r > 0.25 * beta * beta * len && rr > 0.25 * beta * beta * len)) ) {
            *(out++) = s;
        }
    }
}

#endif

