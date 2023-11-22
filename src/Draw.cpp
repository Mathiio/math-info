#include "Draw.hpp"
#include "Point.hpp"
#include "Geogebra_conics.hpp"
#include <iostream>
#include <cstdlib> // for std::rand
#include <ctime> // for std::time


void drawPoint(const Point& point, Viewer_conic& viewer) {
    Eigen::VectorXd pt(2);
    pt << point.getX(), point.getY();

    viewer.push_point(pt, "pt", 200, 0, 0);
}

void drawLine(const Point& point, const Point& point2, Viewer_conic& viewer) {
    Eigen::VectorXd pt1(2), pt2(2);
    
    pt1 << point.getX(), point.getY();
    pt2 << point2.getX(), point2.getY();
    viewer.push_line(pt1, pt2, 200, 200, 0);
}