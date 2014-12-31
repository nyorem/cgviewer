# cgviewer

A simple tool for visualizing 2D CGAL datastructures.

## Features

- Delaunay triangulations
- Crust
- Generate random points in a square

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