#include "../api/Matrix.hpp"

// Matrix

Matrix &Matrix::operator*=(double number) {
    for (unsigned short i = 0; i < height_; ++i) {
        for (unsigned short j = 0; j < width_; ++j) {
            matrix_[i][j] *= number;
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(double number) {
    for (unsigned short i = 0; i < height_; ++i) {
        for (unsigned short j = 0; j < width_; ++j) {
            matrix_[i][j] -= number;
        }
    }
    return *this;
}

Matrix &Matrix::operator+=(double number) {
    for (unsigned short i = 0; i < height_; ++i) {
        for (unsigned short j = 0; j < width_; ++j) {
            matrix_[i][j] += number;
        }
    }
    return *this;
}

Matrix operator+(const Matrix &maxtix, double number) {
    Matrix mat(maxtix);
    mat += number;
    return mat;
}

Matrix operator+(double number, const Matrix &maxtix) {
    Matrix mat(maxtix);
    mat += number;
    return mat;
}

Matrix operator-(const Matrix &maxtix, double number) {
    Matrix mat(maxtix);
    mat -= number;
    return mat;
}

Matrix operator-(double number, const Matrix &maxtix) {
    Matrix mat(maxtix);
    mat -= number;
    return mat;
}

Matrix operator*(const Matrix &maxtix, double number) {
    Matrix mat(maxtix);
    mat *= number;
    return mat;
}

Matrix operator*(double number, const Matrix &maxtix) {
    Matrix mat(maxtix);
    mat *= number;
    return mat;
}

Matrix operator*(const Vector &vector, const Matrix &maxtix) {
    return Matrix(vector, maxtix.GetSize().second) % maxtix;
}

Matrix operator*(const Matrix &maxtix, const String &string) {
    return maxtix % Matrix(string, maxtix.GetSize().first);
}

// String

String &String::operator*=(double number) {
    for (unsigned short i = 0; i < width_; ++i) {
        array_[i] *= number;
    }
    return *this;
}

String &String::operator+=(double number) {
    for (unsigned short i = 0; i < width_; ++i) {
        array_[i] += number;
    }
    return *this;
}

String &String::operator-=(double number) {
    for (unsigned short i = 0; i < width_; ++i) {
        array_[i] -= number;
    }
    return *this;
}

String operator-(const String &vector, double number) {
    String string(vector);
    string -= number;
    return string;
}

String operator-(double number, const String &vector) {
    String string(vector);
    string -= number;
    return string;
}

String operator+(const String &vector, double number) {
    String string(vector);
    string += number;
    return string;
}

String operator+(double number, const String &vector) {
    String string(vector);
    string += number;
    return string;
}

String operator*(const String &vector, double number) {
    String string(vector);
    string *= number;
    return string;
}

String operator*(double number, const String &vector) {
    String string(vector);
    string *= number;
    return string;
}

// Vector

Vector &Vector::operator*=(double number) {
    for (unsigned short i = 0; i < height_; ++i) {
        array_[i] *= number;
    }
    return *this;
}

Vector &Vector::operator+=(double number) {
    for (unsigned short i = 0; i < height_; ++i) {
        array_[i] += number;
    }
    return *this;
}

Vector &Vector::operator-=(double number) {
    for (unsigned short i = 0; i < height_; ++i) {
        array_[i] -= number;
    }
    return *this;
}

Vector operator-(const Vector &vector, double number) {
    Vector vec(vector);
    vec -= number;
    return vec;
}

Vector operator*(double number, const Vector &vector) {
    Vector vec(vector);
    vec *= number;
    return vec;
}

Vector operator*(const Vector &vector, double number) {
    Vector vec(vector);
    vec *= number;
    return vec;
}

Vector operator-(double number, const Vector &vector) {
    Vector vec(vector);
    vec -= number;
    return vec;
}

Vector operator+(const Vector &vector, double number) {
    Vector vec(vector);
    vec += number;
    return vec;
}

Vector operator+(double number, const Vector &vector) {
    Vector vec(vector);
    vec += number;
    return vec;
}