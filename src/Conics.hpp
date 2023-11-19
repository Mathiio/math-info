#pragma once
#include <Eigen/Dense>
#include <vector>

Eigen::VectorXd conicCoefficients(std::vector<Eigen::VectorXd> points, bool isHomogeneous);
Eigen::VectorXd pointTangent(Eigen::VectorXd point, Eigen::VectorXd conic);