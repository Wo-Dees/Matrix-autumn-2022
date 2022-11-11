#pragma once

#include "../api/Vector.hpp"
#include "../api/Matrix.hpp"

#include <vector>

class Vector;
class Matrix;

class String {
public:

    String() = delete;

    explicit String(unsigned short width);
    explicit String(unsigned short width, double number);

    String(const String& string);
    explicit String(const std::vector<double>& vector);
    explicit String(const Matrix& matrix);

    // ScalarCalculations
    String& operator+=(const String& string);
    String& operator-=(const String& string);
    String& operator*=(const String& string);

    // Broadcasting with number
    String& operator*=(double number);
    String& operator+=(double number);
    String& operator-=(double number);

    double operator[](unsigned short i) const;
    double& operator[](unsigned short i);

    Vector Transpose();

private:

    unsigned short width_;
    std::vector<double> array_;

private:

    friend Vector;
    friend String;
    friend Matrix;

};

// ScalarCalculations
String operator+(const String& string_1, const String& string_2);
String operator*(const String& string_1, const String& string_2);
String operator-(const String& string_1, const String& string_2);

// Broadcasting with number
String operator*(const String& vector, double number);
String operator*(double number, const String& vector);
String operator-(const String& vector, double number);
String operator-(double number, const String& vector);
String operator+(const String& vector, double number);
String operator+(double number, const String& vector);
