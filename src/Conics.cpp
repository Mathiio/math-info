#include "Assets.hpp"
#include "Conics.hpp"


Eigen::VectorXd conicCoefficients(std::vector<Eigen::VectorXd> points) {

  Eigen::MatrixXd m_points = generate_matrix(points);
  Eigen::MatrixXd A(5, 6);
  Eigen::VectorXd b(5);

  for (int i = 0; i < 5; ++i) {
    double x = m_points(i, 0);
    double y = m_points(i, 1);

    A.row(i) << x * x, x * y, y * y, x, y, 1.0;
    b(i) = 0.0;
  }

  // Calcul du noyau de A avec une décomposition en valeurs singulières
  Eigen::JacobiSVD <Eigen::MatrixXd> svd (A, Eigen::ComputeThinU | Eigen::ComputeFullV);
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

