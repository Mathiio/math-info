#include "Assets.hpp"
#include <iostream>
#include <cstdlib> // for std::rand
#include <ctime> // for std::time

// Generate a random point in a define interval 
Eigen::VectorXd random_point(bool isHomogeneous, float startInterval, float endInterval) {
    size_t numberCoordinates = isHomogeneous ? 3 : 2;
    Eigen::VectorXd pt(numberCoordinates);

    // Generate pt(0) and pt(1) coordinates in the interval passed as parameter
    pt(0) = startInterval + static_cast<float>(std::rand()) / RAND_MAX * (endInterval - startInterval);
    pt(1) = startInterval + static_cast<float>(std::rand()) / RAND_MAX * (endInterval - startInterval);
    // Check if we are in projective geometry and if we need to add a homogeneous coordinate
    // pt(2) = isHomogeneous ? 1.0 : 0.0;

    return pt;
}

// Generate a matrix of "pointsNumber" points 
Eigen::MatrixXd generate_matrix(std::vector<Eigen::VectorXd> points) {
    Eigen::MatrixXd pts(points.size(), points[0].size());
    // Add to a matrix a "pointsNumber" points 
    for (size_t i = 0; i < points.size(); i++) {
        pts.row(i) = points[i];
    }
    return pts;
}