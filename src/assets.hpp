#pragma once
#include <Eigen/Dense>
#include <vector>

#include "Point.hpp"

Eigen::MatrixXd generate_matrix(const std::vector<Point>& points);
Eigen::VectorXd homoToEucli(const Point& point);
void displayPoint(const Point& point);