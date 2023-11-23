#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Point.hpp"


class Line {
private:
    Point m_pt1;
    Point m_pt2;
    Point m_dir;    
    
    // Update the direction vector
    void updateDirection() {
        // Direction vector using the points
        m_dir = Point(m_pt2.getX() - m_pt1.getX(), m_pt2.getY() - m_pt1.getY(), m_pt2.getW() - m_pt1.getW());
    }

public:
    // Default constructor
    Line()
        : m_pt1(),
          m_pt2(), 
          m_dir() {updateDirection();};

    // Parameters constructor
    Line(float wPt1, float wPt2)
        : m_pt1(wPt1),
          m_pt2(wPt2), 
          m_dir() {updateDirection();};

    Line(float xPt1, float yPt1, float wPt1, float xPt2, float yPt2, float wPt2)
        : m_pt1(xPt1, yPt1, wPt1),
          m_pt2(xPt2, yPt2, wPt2), 
          m_dir() {updateDirection();};

    Line(Point pt1, Point pt2)
        : m_pt1(pt1.getX(), pt1.getY(), 1),
          m_pt2(pt2.getX(), pt2.getY(), 1), 
          m_dir() {updateDirection();};

    // Destructor
    ~Line() = default;

    // Getters
    Point getPt1() const {return m_pt1;}
    Point getPt2() const {return m_pt2;}
    Point getDirection() const {return m_dir;}

    // Setters
    void setPt1(const Point& pt1) {
        m_pt1 = pt1;
        updateDirection();
    }

    void setPt2(const Point& pt2) {
        m_pt2 = pt2;
        updateDirection();
    }
};
