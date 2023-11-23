#include "Draw.hpp"
#include "Geogebra_conics.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


//* Draw a point
void drawPoint(const Point& point, Viewer_conic& viewer) {
    Eigen::VectorXd pt(2);
    pt << point.getX(), point.getY();

    viewer.push_point(pt, "pt", 200, 0, 0);
}

//* Draw a line
void drawLine(const Line& line, Viewer_conic& viewer) {
    Eigen::VectorXd pt1(2), dir(2);
    
    pt1 << line.getPt1().getX(), line.getPt1().getY();
    dir << line.getDirection().getX(), line.getDirection().getY();

    viewer.push_line(pt1, dir, 200, 200, 0);
}