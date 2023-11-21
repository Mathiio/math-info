#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <Eigen/Dense>


class Point {
private:
    Eigen::Vector3f m_coordinates;

public:
    // Default constructor
    Point()
        : m_coordinates(randomCoordinate(), randomCoordinate(), 1.0f) {};

    // Parameters constructor
    Point(float w)
        : m_coordinates(randomCoordinate(), randomCoordinate(), w) {};

    Point(float x, float y, float w)
        : m_coordinates(x, y, w) {};

    // Destructor
    ~Point() = default;

    // Getter
    float getX() const {return m_coordinates(0);};
    float getY() const {return m_coordinates(1);};
    float getW() const {return m_coordinates(2);};

    // Setter
    void setX(float x) {m_coordinates(0) = x;};
    void setY(float y) {m_coordinates(1) = y;};
    void setW(float w) {m_coordinates(2) = w;};

    Point operator-(const Point& other) {
        this->setX(this->getX() - other.getX());
        this->setY(this->getY() - other.getY());
        this->setW(this->getW() - other.getW());
    }

    Point operator=(const Point& other) {
        this->setX(other.getX());
        this->setY(other.getY());
        this->setW(other.getW());
    }

private:
    float randomCoordinate() const {
        return -5.0f + static_cast<float>(std::rand()) / RAND_MAX * (5.0f - (-5.0f));
    }
};
