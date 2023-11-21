#include <iostream>
#include <vector>
#include <ctime> // for std::time

#include <Eigen/Dense>

#include "Geogebra_conics.hpp"
#include "Conics.hpp"
#include "Assets.hpp"
#include "Point.hpp"
#include "Line.hpp"

bool isGeomProject = true;
int startInterval = -5;
int endInterval = 5;

int main() {

  // Création d'un Point avec des coordonnées aléatoires
  Point pt;

  // Affichage des coordonnées du point
  std::cout << "Coordonnées du point aléatoire : " << std::endl;
  std::cout << "X : " << pt.getX() << std::endl;
  std::cout << "Y : " << pt.getY() << std::endl;
  std::cout << "W : " << pt.getW() << std::endl;



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
  Point points;
s
  for (size_t i = 0; i < numberPoints; i++) {
    Point point;
    points.push_back(point);

    //if(isGeomProject) point = homoToEucli(point);
    /*Eigen::VectorXd pt(2);
    pt << point.getX(), point.getY();

    viewer.push_point(pt, "pt", 200, 0, 0);*/
    displayPoint(point, viewer);
  }

  // draw conic
  /*Eigen::VectorXd conic = conicCoefficients(points);
  std::cout << conic.size() << std::endl;
  viewer.push_conic(conic, 0, 0, 200);*/

  // draw line
  Line line1;
  //if(isGeomProject) line1.setPt1() = homoToEucli(line1.getPt1());
  //viewer.push_line(line1.getPt1(), pointTangent(line1.getPt1(), conic), 200, 200, 0);

  // render
  viewer.display(); // on terminal
  viewer.render("output.html");  // generate the output file (to open with your web browser)

  return 0;
}

