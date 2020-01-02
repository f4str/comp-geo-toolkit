# Computational Geometry Toolkit

## Overview

A simple C library for algorithms in computational geometry. 

## Requirements

* GCC
* make

On Ubuntu, all dependencies can be installed using apt:
```bash
sudo apt install build-essentials
```

## Credits

Most of the data structures were implemented based on the C++ STL such as vector and map. Many of the algorithms are based on the book *Computational Geometry in C* by Joseph O'Rourke. 

## Implemented Algorithms

### **Point and Segment**

* Point on left side of line - *O(1)*
* Point on right side of line - *O(1)*
* Collinear points - *O(1)*
* Intersection between two lines - *O(1)*

### **Polygon**

* Area of polygon - *O(n)*
* Two vertices form a diagonal - *O(n)*

### **Triangulations**

* Ear Clipping - *O(n<sup>2</sup>)*

### **Convex Hull**

* Graham Scan - *O(n log n)*
* Jarvis March - *O(nh)*
* Divide-and-Conquer - *O(n log n)*
* Quickhull - *O(n<sup>2</sup>)*
