#pragma once

#include "../api/String.hpp"
#include "../api/Matrix.hpp"

#include <vector>

class String;
class Matrix;

class Vector {
public:

    Vector() = delete;

    explicit Vector(unsigned short height);
    explicit Vector(unsigned short height, double number);

    Vector(const Vector& vector);
    explicit Vector(const std::vector<double>& vector);
    explicit Vector(const Matrix& matrix);

    // ScalarCalculations
    Vector& operator+=(const Vector& vector);
    Vector& operator-=(const Vector& vector);
    Vector& operator*=(const Vector& vector);

    // Broadcasting with number
    Vector& operator*=(double number);
    Vector& operator+=(double number);
    Vector& operator-=(double number);

    double operator[](unsigned short i) const;
    double& operator[](unsigned short i);

    String Transpose();

private:

    unsigned short height_;
    std::vector<double> array_;

private:
    friend Matrix;
};

// ScalarCalculations
Vector operator+(const Vector& vector_1, const Vector& vector_2);
Vector operator*(const Vector& vector_1, const Vector& vector_2);
Vector operator-(const Vector& vector_1, const Vector& vector_2);

// Broadcasting with number
Vector operator*(const Vector& vector, double number);
Vector operator*(double number, const Vector& vector);
Vector operator-(const Vector& vector, double number);
Vector operator-(double number, const Vector& vector);
Vector operator+(const Vector& vector, double number);
Vector operator+(double number, const Vector& vector);
