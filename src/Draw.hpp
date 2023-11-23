#pragma once
#include <Eigen/Dense>
#include <vector>

#include "Geogebra_conics.hpp"
#include "Point.hpp"
#include "Line.hpp"


void drawPoint(const Point& point, Viewer_conic &viewer);
void drawLine(const Line& line, Viewer_conic& viewer);