#pragma once
#include <Eigen/Dense>
#include <vector>

#include "Geogebra_conics.hpp"
#include "Point.hpp"
#include "Line.hpp"

Eigen::MatrixXd generate_matrix(const std::vector<Point>& points);
Eigen::VectorXd homoToEucli(const Point& point);
void displayPoint(const Point& point, Viewer_conic &viewer);
void displayTangent(const Point& point, const Point& point2, Viewer_conic& viewer);