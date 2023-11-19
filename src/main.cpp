#include <iostream>
#include <vector>
#include <ctime> // for std::time

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"
#include "Conics.hpp"
#include "Assets.hpp"

bool isHomogeneous = false;
int startInterval = -5;
int endInterval = 5;

int main() {
  size_t numberPoints = 5;
  std::srand(static_cast<unsigned>(std::time(0)));
  // the viewer will open a file whose path is writen in hard (bad!!). 
  // So you should either launch your program from the fine directory or change the path to this file.
  Viewer_conic viewer;

  // viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);

  // draw points
  std::vector<Eigen::VectorXd> points;

  for (size_t i = 0; i < numberPoints; i++) {
    Eigen::VectorXd point = random_point(isHomogeneous, startInterval, endInterval);
    points.push_back(point);
    viewer.push_point(point, "pt", 200, 0, 0);
  }

  // draw conic
  Eigen::VectorXd conic = conicCoefficients(points);
  viewer.push_conic(conic, 0, 0, 200);

  // draw line
  viewer.push_line(points[0], pointTangent(points[0], conic),  200,200,0);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}

