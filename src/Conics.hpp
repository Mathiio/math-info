#pragma once
#include <Eigen/Dense>
#include <vector>

#include "Point.hpp"


Eigen::VectorXd conicCoefficients(const std::vector<Point>& points);
Point pointTangent(const Point& point, const Eigen::VectorXd& conic);