#include "Maths.hpp"

#include <iostream>
#include <vector>
#include <Eigen/Dense>

Eigen::VectorXd conicCoefficients(const Eigen::MatrixXd& points) {
  // Vérification du nombre de points de la matrice
  if (points.rows() < 5 || points.cols() != 2) {
    std::cerr << "Erreur : Il faut au moins 5 points avec des coordonnées (x, y)." << std::endl;
    return Eigen::VectorXd(); // Retourne un vecteur vide en cas d'erreur
  }

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