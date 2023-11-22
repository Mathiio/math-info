#include <iostream>
#include "Draw.hpp"
#include "Conics.hpp"
#include "Point.hpp"


Eigen::VectorXd conicCoefficients(const std::vector<Point>& points) {
  Eigen::MatrixXd A(points.size(), 6);

  for (size_t i = 0; i < points.size(); i++) {
    double x = points[i].getX();
    double y = points[i].getY();
    double w = points[i].getW();

    A.row(i) << x * x, x * y, y * y, x * w, y * w, w * w;
  }

  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
  Eigen::VectorXd solution = svd.matrixV().rightCols(1);

  return solution;
}

Point pointTangent(const Point& point, const Eigen::VectorXd& conic) {
  double slope = -(2 * conic[0] * point.getX() + conic[1] * point.getY() + conic[3]) /
                  (conic[1] * point.getX() + 2 * conic[2] * point.getY() + conic[4]);
                
  double yIntercept = point.getY() - slope * point.getX();

  Point secondPoint(point.getX()+1, slope * (point.getX()+1) + yIntercept, 1);
  secondPoint-point;
  
  return secondPoint;
}


