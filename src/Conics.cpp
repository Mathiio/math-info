#include "Assets.hpp"
#include "Conics.hpp"


Eigen::VectorXd conicCoefficients() {

  Eigen::MatrixXd points = generate_matrix(5, false, -5, 5);
  Eigen::MatrixXd A(5, 6);
  Eigen::VectorXd b(5);

  for (int i = 0; i < 5; ++i) {
    double x = points(i, 0);
    double y = points(i, 1);

    A.row(i) << x * x, x * y, y * y, x, y, 1.0;
    b(i) = 0.0;
  }

  // Calcul du noyau de A avec une décomposition en valeurs singulières
  Eigen::JacobiSVD < Eigen::MatrixXd > svd (A, Eigen::ComputeThinU | Eigen::ComputeFullV);
  Eigen::VectorXd solution = svd.matrixV().rightCols(1);

  return solution;
}

