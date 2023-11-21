#include <iostream>
#include "Assets.hpp"
#include "Conics.hpp"
#include "Point.hpp"


Eigen::VectorXd conicCoefficients(const std::vector<Point>& points) {
    Eigen::MatrixXd A(points.size(), 6);
    Eigen::VectorXd b(points.size());

    for (size_t i = 0; i < points.size(); i++) {
        double x = points[i].getX();
        double y = points[i].getY();
        double w = points[i].getW();

        A.row(i) << x * x, x * y, y * y, x * w, y * w, w * w;
        b(i) = 0.0;
    }

    Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
    Eigen::VectorXd solution = svd.matrixV().rightCols(1);

    return solution;
}


Point pointTangent(const Point& point, const Eigen::VectorXd& conic) {
    double slope = -(2 * conic[0] * point.getX() + conic[1] * point.getY() + conic[3]) /
                   (conic[1] * point.getX() + 2 * conic[2] * point.getY() + conic[4]);

    double yIntercept = point.getY() - slope * point.getX();

    Point secondPoint(point.getX() + 1, slope * (point.getX() + 1) + yIntercept, 1);
    Point newPoint = secondPoint - point;
    
    return newPoint;
}



// Eigen::VectorXd pointTangent(Point<float>& point, Eigen::VectorXd conic) {
//   // Calculez le coefficient directeur de la tangente
//   double slope = -(2 * conic[0] * point.getX() + conic[1] * point.getY() + conic[3]) / 
//                 (conic[1] * point.getX() + 2 * conic[2] * point.getY() + conic[4]);

//   // Calculez l'ordonnée à l'origine de la tangente
//   double yIntercept = point.getY() - slope * point.getX();

//   // Calculez le deuxième point sur la tangente
//   Eigen::VectorXd secondPoint(2);
//   secondPoint << point.getX() + 1, slope * (point.getX() + 1) + yIntercept;

//   return (secondPoint - point);
// }




// Eigen::VectorXd conicCoefficients(std::vector<Point<float>> points, bool isHomogeneous) {
//   Eigen::MatrixXd A(points.size(), 6);
//   Eigen::VectorXd b(points.size());

//   for (size_t i = 0; i < points.size(); i++) {
//     double x = points[i].getX();
//     double y = points[i].getY();
//     double w = points[i].getW();
//     //double w = (isHomogeneous) ? points[i](2) : 1.0;

//     // Remplissez les termes en fonction de la géométrie
//     A.row(i) << x * x, x * y, y * y, x * w, y * w, w * w;

//     b(i) = 0.0;
//   }

//   // Calcul du noyau de A avec une décomposition en valeurs singulières
//   Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
//   Eigen::VectorXd solution = svd.matrixV().rightCols(1);

//   return solution;
// }