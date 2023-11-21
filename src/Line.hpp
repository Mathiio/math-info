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
    // Default constructor with random points
    Line()
        : m_pt1(),
          m_pt2() {};

    // Parameters constructor with specified points
    Line(float wPt1, float wPt2)
        : m_pt1(wPt1),
          m_pt2(wPt2) {};

    // Parameters constructor with specified points
    Line(float xPt1, float yPt1, float wPt1, float xPt2, float yPt2, float wPt2)
        : m_pt1(xPt1, yPt1, wPt1),
          m_pt2(xPt2, yPt2, wPt2) {};

    // Destructor
    ~Line() = default;

    // Getter functions
    Point getPt1() const { return m_pt1; }
    Point getPt2() const { return m_pt2; }

    // Setter functions
    void setPt1(const Point& pt1) { m_pt1 = pt1; }
    void setPt2(const Point& pt2) { m_pt2 = pt2; }
};


// template <typename T>
// class Line {
// private:
//     Point<T> m_pt1;
//     Point<T> m_pt2;

// public:
//     // Default constructor with random points
//     Line()
//         : m_pt1(),
//           m_pt2() {};

//     // Parameters constructor with specified points
//     Line(T x_pt1, T y_pt1, T w_pt1, T x_pt2, T y_pt2, T w_pt2)
//         : m_pt1(x_pt1, y_pt1, w_pt1),
//           m_pt2(x_pt2, y_pt2, w_pt2) {};
    
//     // Parameters constructor with specified points
//     Line(T w_pt1, T w_pt2)
//         : m_pt1(w_pt1),
//           m_pt2(w_pt2) {};

//     // Destructor
//     ~Line() = default;

//     // Getter functions
//     Point<T> getPt1() const { return m_pt1; }
//     Point<T> getPt2() const { return m_pt2; }

//     // Setter functions
//     void setPt1(const Point<T>& pt1) { m_pt1 = pt1; }
//     void setPt2(const Point<T>& pt2) { m_pt2 = pt2; }
// };