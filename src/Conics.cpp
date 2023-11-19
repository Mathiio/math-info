#include <iostream>
#include "Assets.hpp"
#include "Conics.hpp"


Eigen::VectorXd conicCoefficients(std::vector<Eigen::VectorXd> points, bool isHomogeneous) {
  Eigen::MatrixXd A(points.size(), 6);
  Eigen::VectorXd b(points.size());

  for (size_t i = 0; i < points.size(); ++i) {
    double x = points[i](0);
    double y = points[i](1);
    double w = (isHomogeneous) ? points[i](2) : 1.0;

    // Remplissez les termes en fonction de la géométrie
    A.row(i) << x * x, x * y, y * y, x * w, y * w, w * w;

    b(i) = 0.0;
  }

  // Calcul du noyau de A avec une décomposition en valeurs singulières
  Eigen::JacobiSVD<Eigen::MatrixXd> svd(A, Eigen::ComputeThinU | Eigen::ComputeFullV);
  Eigen::VectorXd solution = svd.matrixV().rightCols(1);

  return solution;
}

Eigen::VectorXd pointTangent(Eigen::VectorXd point, Eigen::VectorXd conic) {
  // Calculez le coefficient directeur de la tangente
  double slope = -(2 * conic[0] * point(0) + conic[1] * point(1) + conic[3]) / 
                (conic[1] * point(0) + 2 * conic[2] * point(1) + conic[4]);

  // Calculez l'ordonnée à l'origine de la tangente
  double yIntercept = point(1) - slope * point(0);

  // Calculez le deuxième point sur la tangente
  Eigen::VectorXd secondPoint(2);
  secondPoint << point(0) + 1, slope * (point(0) + 1) + yIntercept;

  return (secondPoint - point);
}

