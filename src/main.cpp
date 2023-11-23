// Librairies
#include <iostream>
#include <vector>
#include <ctime>
#include <Eigen/Dense>

// Header files
#include "Geogebra_conics.hpp"
#include "Conics.hpp"
#include "Draw.hpp"
#include "Point.hpp"
#include "Line.hpp"

//* Select the desired display
//  • 1 --> 5 points
//  • 2 --> 5 points + conic
//  • 3 --> 5 points + conic + tangent
//  • 4 --> 6 points + conic
//  • 5 --> 5 tangents + conic

const unsigned int step = 3;

//* Lower and upper bound of the coordinate range for random points
int startInterval = -5;
int endInterval = 5;

int main() {
  //* Check if step is valid
  assert(step >= 1 && step <= 5);

  std::srand(static_cast<unsigned>(std::time(0)));
  Viewer_conic viewer;

  //* Viewer options
  viewer.set_background_color(250, 250, 255);
  viewer.show_axis(true);
  viewer.show_grid(false);
  viewer.show_value(false);
  viewer.show_label(true);

  if (step != 5)  {
    //* Number of points to determine the conic
    size_t numberPoints = step == 4 ? 6 : 5;  

    std::vector<Point> points;

    //* Draw points
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

        Line tangent(points[0], pointT);
        drawLine(tangent, viewer);
      }
    }
  }

  //* Step 5
  else if (step == 5) {
    std::vector<Line> tangents;

    //* Draw tangents
    for (size_t i = 0; i < 5; i++) {
      Line tangent;
      drawLine(tangent, viewer);
      tangents.push_back(tangent);
    }

    //* Get the conic coefficients from the tangents
    std::vector<Point> conicPoints = conicCoefficientsTangent(tangents);

    Eigen::VectorXd conicTangent = conicCoefficients(conicPoints);
    viewer.push_conic(conicTangent, 0, 0, 200);
  }
  
  //* Render
  viewer.display();
  viewer.render("output.html"); // Open with weeb browser

  return 0;
}

