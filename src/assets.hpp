#pragma once
#include <Eigen/Dense>
#include <vector>

Eigen::VectorXd random_point(bool isHomogeneous, float startInterval, float endInterval);
Eigen::MatrixXd generate_matrix(std::vector<Eigen::VectorXd> points);
Eigen::VectorXd homoToEucli(Eigen::VectorXd& point);