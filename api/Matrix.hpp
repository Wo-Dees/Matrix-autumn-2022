#pragma once

#include "../api/Vector.hpp"
#include "../api/String.hpp"

#include <vector>

#include <ostream>

class Vector;
class String;

class Matrix {
public:

    Matrix() = delete;

    Matrix(unsigned short height, unsigned short width);
    Matrix(unsigned short height, unsigned short width, double number);

    explicit Matrix(const Vector& vector);
    explicit Matrix(const String& string);

    Matrix(const Vector& vector, unsigned short n);
    Matrix(const String& string, unsigned short n);

    Matrix(const Matrix& matrix);
    explicit Matrix(const std::vector<std::vector<double>>& matrix);

    // GetData
    [[nodiscard]] std::vector<double> GetDiagonal() const;
    [[nodiscard]] String GetString(unsigned short i) const;
    [[nodiscard]] Vector GetColumn(unsigned short i) const;
    [[nodiscard]] std::pair<unsigned short, unsigned short> GetSize() const;

    // ScalarCalculations
    Matrix& operator+=(const Matrix& maxtix);
    Matrix& operator-=(const Matrix& maxtix);
    Matrix& operator*=(const Matrix& maxtix);

    // MatrixCalculations
    Matrix& operator%=(const Matrix& maxtix);

    // Broadcasting with number
    Matrix& operator*=(double number);
    Matrix& operator-=(double number);
    Matrix& operator+=(double number);

    String operator[](unsigned short i) const;
    std::vector<double>& operator[](unsigned short i);

    Matrix Transpose() const;
    Matrix Inverse() const;
    double GetDeterminant() const;

private:

    unsigned short height_;
    unsigned short width_;
    std::vector<std::vector<double>> matrix_;

private:

    friend Vector;
    friend String;

};

// ScalarCalculations
Matrix operator+(const Matrix& maxtix_1, const Matrix& maxtix_2);
Matrix operator-(const Matrix& maxtix_1, const Matrix& maxtix_2);
Matrix operator*(const Matrix& maxtix_1, const Matrix& maxtix_2);

// Broadcasting with number
Matrix operator+(const Matrix& maxtix, double number);
Matrix operator+(double number, const Matrix& maxtix);
Matrix operator-(const Matrix& maxtix, double number);
Matrix operator-(double number, const Matrix& maxtix);
Matrix operator*(const Matrix& maxtix, double number);
Matrix operator*(double number, const Matrix& maxtix);

// Broadcasting with vectors and strings
Matrix operator*(const Vector& vector, const Matrix& maxtix);
Matrix operator*(const Matrix& maxtix, const String& string);

// MatrixCalculations
Matrix operator%(const Matrix& maxtix_1, const Matrix& maxtix_2);
Vector operator%(const Matrix& maxtix, const Vector& vector);
String operator%(const String& string, const Matrix& maxtix);

bool operator==(const Matrix& matrix_1, const Matrix& matrix_2);
bool operator!=(const Matrix& matrix_1, const Matrix& matrix_2);

std::ostream &operator<<(std::ostream& os, const Matrix& matrix);
