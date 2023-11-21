#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Point.hpp"


class Line {
private:
    Point m_pt1;
    Point m_pt2;

public:
    // Default constructor
    Line()
        : m_pt1(),
          m_pt2() {};

    // Parameters constructor
    Line(float wPt1, float wPt2)
        : m_pt1(wPt1),
          m_pt2(wPt2) {};

    Line(float xPt1, float yPt1, float wPt1, float xPt2, float yPt2, float wPt2)
        : m_pt1(xPt1, yPt1, wPt1),
          m_pt2(xPt2, yPt2, wPt2) {};

    // Destructor
    ~Line() = default;

    // Getter
    Point getPt1() const { return m_pt1; }
    Point getPt2() const { return m_pt2; }

    // Setter
    void setPt1(const Point& pt1) { m_pt1 = pt1; }
    void setPt2(const Point& pt2) { m_pt2 = pt2; }
};
