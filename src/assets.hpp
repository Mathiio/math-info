#pragma once
#include <Eigen/Dense>
#include <vector>

Eigen::VectorXd random_point(bool isHomogeneous, float startInterval, float endInterval);
Eigen::MatrixXd generate_matrix(const size_t &pointsNumber, bool isHomogeneous, float startInterval, float endInterval);