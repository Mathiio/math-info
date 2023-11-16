#include <iostream>
#include <vector>

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"
#include "Maths.hpp"

int main() {
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
  Eigen::VectorXd pt1(2), pt2(2), pt3(2), pt4(2), pt5(2);
  pt1 <<  1.0, 1.0;
  pt2 <<  2.0, 4.0;
  pt3 << -1.0, 2.0;
  pt4 <<  3.0, 1.0;
  pt5 <<  0.0, 3.0;

  Eigen::MatrixXd points(5, 2);
  points << 1.0, 1.0,
            2.0, 4.0,
            -1.0, 2.0,
            3.0, 1.0,
            0.0, 3.0;

  viewer.push_point(pt1, "a", 200,0,0);
  viewer.push_point(pt2, "b", 200,0,0);
  viewer.push_point(pt3, "c", 200,0,0);
  viewer.push_point(pt4, "d", 200,0,0);
  viewer.push_point(pt5, "e", 200,0,0);

  // draw line
  // viewer.push_line(pt1, pt2-pt1,  200,200,0);

  // draw conic
  Eigen::VectorXd conic(6);
  conic << conicCoefficients(points);
  viewer.push_conic(conic, 0,0,200);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}

