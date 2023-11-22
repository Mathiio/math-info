#include <iostream>
#include <vector>
#include <ctime> // for std::time

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"
#include "Conics.hpp"
#include "Draw.hpp"
#include "Point.hpp"
#include "Line.hpp"

// Choose what you want the display to see
//  • 1 --> 5 points
//  • 2 --> 5 points + conic
//  • 3 --> 5 points + conic + tangent
//  • 4 --> 6 points + conic
//  • 5 --> 5 tangents

const unsigned int step = 5;

// Lower and upper bound of the coordinate range for random points
int startInterval = -5;
int endInterval = 5;

int main() {
  assert(step >= 1 && step <= 5);
  size_t numberPoints = step == 4 ? 6 : 5;  

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

  //* Draw points
  if (step != 5)  {
    std::vector<Point> points;

    for (size_t i = 0; i < numberPoints; i++) {
      Point point;
      points.push_back(point);
      drawPoint(point, viewer);
    }

    //* Draw conic
    if (!(step == 1 || step == 5)) {
      Eigen::VectorXd conic = conicCoefficients(points);
      viewer.push_conic(conic, 0, 0, 200);

      //* Draw tangent
      if (step == 3) {
        Point pointT; 
        pointT = pointTangent(points[0], conic);

        drawLine(points[0], pointT, viewer);
      }
    }
  }
  else if (step == 5) {
    //* Draw line
    for (size_t i = 0; i < 5; i++) {
      Line line;
      drawLine(line.getPt1(), line.getPt2(), viewer);
    }
  }
  
  //* Render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}

