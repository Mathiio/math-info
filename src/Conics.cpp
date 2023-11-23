#include <iostream>
#include "Conics.hpp"
#include "Point.hpp"
#include "Line.hpp"


//* Calculate the conic's coefficients from points
Eigen::VectorXd conicCoefficients(const std::vector<Point>& points) {
  Eigen::MatrixXd A(points.size(), 6);

  for (size_t i = 0; i < points.size(); i++) {
    double x = points[i].getX();
    double y = points[i].getY();
    double w = points[i].getW();

    A.row(i) << x*x, x*y, y*y, x*w, y*w, w*w;
  }

  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
  Eigen::VectorXd solution = svd.matrixV().rightCols(1);

  return solution;
}

//* Determine a new point on the tangent
Point pointTangent(const Point& point, const Eigen::VectorXd& conic) {
  double slope = -(2 * conic[0] * point.getX() + conic[1] * point.getY() + conic[3]) /
                  (conic[1] * point.getX() + 2 * conic[2] * point.getY() + conic[4]);
                
  double yIntercept = point.getY() - slope * point.getX();

  Point secondPoint(point.getX()+1, slope * (point.getX()+1) + yIntercept, 1);
  
  return secondPoint;
}

//* Find the intersection between two lines
Point findIntersection(const Line& line1, const Line& line2) {
  Point intersection;

  double m1 = line1.getDirection().getY() / line1.getDirection().getX();
  double c1 = line1.getPt1().getY() - m1 * line1.getPt1().getX();

  double m2 = line2.getDirection().getY() / line2.getDirection().getX();
  double c2 = line2.getPt1().getY() - m2 * line2.getPt1().getX();

  double x = (c2-c1)/(m1-m2);
  double y = m1*x + c1;

  intersection.setX(x);
  intersection.setY(y);

  return intersection;
}

//* Calculate the conic's coefficients from tangent
std::vector<Point> conicCoefficientsTangent(std::vector<Line> tangents) {
  std::vector<Point> pointsTangent;
  std::vector<Point> pointsConic;

  for (size_t i = 0; i < 5; i++) {
    Point pt1, pt2;
    pt1.setX(tangents[i].getPt1().getX());
    pt1.setY(tangents[i].getPt1().getY());

    pt2.setX(tangents[i].getPt2().getX());
    pt2.setY(tangents[i].getPt2().getY());

    pointsTangent.push_back(pt1);
    pointsTangent.push_back(pt2);
  }

  for (int i = 0; i < 5; i++) {
    Point pointIntersect, intersection;

    Line tangent = tangents[i];

    Line diag1(pointsTangent[i], pointsTangent[(i+2)%5]);
    Line diag2(pointsTangent[(i+1)%5], pointsTangent[(i+4)%5]);

    intersection = findIntersection(diag1, diag2);

    Line diag3(pointsTangent[(i+3)%5], intersection);

    pointsConic.push_back(findIntersection(tangent, diag3));
  }

  return pointsConic;
}


