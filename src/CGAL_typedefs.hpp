#ifndef _CGAL_TYPEDEFS_HPP_
#define _CGAL_TYPEDEFS_HPP_

#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <vector>
#include "QDelaunayTriangulationItem.hpp"

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;
typedef Kernel::FT FT;

// Basic geometric types
typedef CGAL::Line_2<Kernel> Line_2;
typedef CGAL::Point_2<Kernel> Point_2;
typedef CGAL::Segment_2<Kernel> Segment_2;
typedef CGAL::Triangle_2<Kernel> Triangle_2;
typedef CGAL::Vector_2<Kernel> Vector_2;

typedef std::vector<Point_2> Points_2;
typedef std::vector<Segment_2> Segments_2;

// Delaunay triangulations
typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay_triangulation_2;
typedef QDelaunayTriangulationItem<Delaunay_triangulation_2> QDelaunayTriangulation2Item;

#endif

