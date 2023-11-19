#pragma once
#include <Eigen/Dense>
#include <vector>

Eigen::VectorXd conicCoefficients(std::vector<Eigen::VectorXd> points);
Eigen::VectorXd pointTangent(Eigen::VectorXd point, Eigen::VectorXd conic);