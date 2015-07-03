# cgviewer

A simple tool for visualizing 2D CGAL datastructures.

## Features

- Generate random points in a square, on an ellipse
- Delaunay triangulations, Voronoi vertices and edges
- Compute the Crust
- Compute the beta-skeleton
- Load and save point clouds

## Dependencies

- cmake
- Qt5
- CGAL

## Building
```
mkdir build
cd build
cmake .. -DCGAL_DIR=$CGAL_DIR
make
```

where `CGAL_DIR` is the root of your CGAL installation directory.
