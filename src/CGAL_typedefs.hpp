#ifndef _CGAL_TYPEDEFS_HPP_
#define _CGAL_TYPEDEFS_HPP_

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Delaunay_triangulation_2.h>
#include <CGAL/Regular_triangulation_euclidean_traits_2.h>
#include <CGAL/Regular_triangulation_2.h>

#include <vector>

#include "QRegularTriangulationItem.hpp"
#include "QDelaunayTriangulationItem.hpp"

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

// Basic geometric types
typedef CGAL::Point_2<Kernel> Point_2;
typedef CGAL::Segment_2<Kernel> Segment_2;

typedef std::vector<Point_2> Points_2;
typedef std::vector<Segment_2> Segments_2;

typedef CGAL::Triangle_2<Kernel> Triangle_2;

typedef CGAL::Line_2<Kernel> Line_2;

typedef Kernel::FT FT;

// Delaunay triangulations
typedef CGAL::Delaunay_triangulation_2<Kernel> Delaunay_triangulation_2;
typedef QDelaunayTriangulationItem<Delaunay_triangulation_2> QDelaunayTriangulation2Item;

// Regular triangulations
typedef CGAL::Regular_triangulation_euclidean_traits_2<Kernel> Traits;
typedef Traits::Weighted_point_2 Weighted_point_2;
typedef CGAL::Regular_triangulation_2<Traits> Regular_triangulation_2;
typedef QRegularTriangulationItem<Regular_triangulation_2> QRegularTriangulation2Item;

#endif

