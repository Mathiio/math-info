#include "Assets.hpp"
#include "Point.hpp"
#include "Geogebra_conics.hpp"
#include <iostream>
#include <cstdlib> // for std::rand
#include <ctime> // for std::time


Eigen::MatrixXd generate_matrix(const std::vector<Point>& points) {
    Eigen::MatrixXd pts(points.size(), 3); // Assuming points are 3D (Eigen::Vector3d)
    
    for (size_t i = 0; i < points.size(); i++) {
        pts.row(i) << points[i].getX(), points[i].getY(), points[i].getW();
    }
    
    return pts;
}

Eigen::VectorXd homoToEucli(const Point& point) {
    Eigen::MatrixXd euclideanPoint((point.getX()/point.getW()), (point.getY()/point.getW()));
    return euclideanPoint;
}

void displayPoint(const Point& point, Viewer_conic& viewer) {
    Eigen::VectorXd pt(2);
    pt << point.getX(), point.getY();

    viewer.push_point(point, "pt", 200, 0, 0);
}



// Generate a matrix of "pointsNumber" points 
// Eigen::MatrixXd generate_matrix(std::vector<Eigen::VectorXd> points) {
//     Eigen::MatrixXd pts(points.size(), points[0].size());
//     // Add to a matrix a "pointsNumber" points 
//     for (size_t i = 0; i < points.size(); i++) {
//         pts.row(i) = points[i];
//     }
//     return pts;
// }

// Point<float> homoToEucli(Point<float>& point) {
//     //assert(point[2]!=0 && "Point a l'infini");

//     Point<float> euclideanPoint;
//     euclideanPoint.setX(point.getX());
//     euclideanPoint.setY(point.getY());
//     euclideanPoint.setW(point.getW());
//     return euclideanPoint;
// }