#pragma once
#include <Eigen/Dense>
#include <vector>
#include "Point.hpp"
#include "Line.hpp"


Eigen::VectorXd conicCoefficients(const std::vector<Point>& points);
Point pointTangent(const Point& point, const Eigen::VectorXd& conic);
Point findIntersection(const Line& line1, const Line& line2);
std::vector<Point> conicCoefficientsTangent(std::vector<Line> tangents);