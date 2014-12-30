#ifndef _CGAL_TYPEDEFS_HPP_
#define _CGAL_TYPEDEFS_HPP_

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <vector>

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

typedef CGAL::Point_2<Kernel> Point_2;
typedef CGAL::Segment_2<Kernel> Segment_2;

typedef std::vector<Point_2> Points_2;
typedef std::vector<Segment_2> Segments_2;

typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay_triangulation_2;

#endif

