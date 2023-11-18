#include "Assets.hpp"


// Generate a random point in a define interval 
Eigen::VectorXd random_point(bool isHomogeneous, float startInterval, float endInterval) {
    Eigen::VectorXd pt(3);
    // Generates pt(0) and pt(1) coordinates in the interval passed as parameter
    pt(0) = startInterval + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (endInterval - startInterval)));
    pt(1) = startInterval + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (endInterval - startInterval)));
    // Check if we are in projective geometry and if we need to add a homogeneous corrdonnée
    pt(2) = isHomogeneous ? 1.0 : 0.0;

    return pt;
}


// Generate a matrix of "pointsNumber" points 
Eigen::MatrixXd generate_matrix(const size_t &pointsNumber, bool isHomogeneous, float startInterval, float endInterval) {
    Eigen::MatrixXd pts(pointsNumber, 3);
    // Add to a matrix a "pointsNumber" points 
    for (size_t i = 0; i < pointsNumber; i++) {
        // Call the fonction "random" to generate a point
        pts.row(i) = random_point(isHomogeneous, startInterval, endInterval);
    }
    return pts;
}