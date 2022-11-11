#include "../api/Matrix.hpp"
#include "../api/String.hpp"


// Matrix

Matrix &Matrix::operator+=(const Matrix &maxtix) {
    for (unsigned short i = 0; i < height_; ++i) {
        for (unsigned short j = 0; j < width_; ++j) {
            matrix_[i][j] += maxtix.matrix_[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &maxtix) {
    for (unsigned short i = 0; i < height_; ++i) {
        for (unsigned short j = 0; j < width_; ++j) {
            matrix_[i][j] -= maxtix.matrix_[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(const Matrix &maxtix) {
    for (unsigned short i = 0; i < height_; ++i) {
        for (unsigned short j = 0; j < width_; ++j) {
            matrix_[i][j] *= maxtix.matrix_[i][j];
        }
    }
    return *this;
}

Matrix operator+(const Matrix &maxtix_1, const Matrix &maxtix_2) {
    Matrix maxtix(maxtix_1);
    maxtix += maxtix_2;
    return maxtix;
}

Matrix operator-(const Matrix &maxtix_1, const Matrix &maxtix_2) {
    Matrix maxtix(maxtix_1);
    maxtix -= maxtix_2;
    return maxtix;
}

Matrix operator*(const Matrix &maxtix_1, const Matrix &maxtix_2) {
    Matrix maxtix(maxtix_1);
    maxtix *= maxtix_2;
    return maxtix;
}

// String

String &String::operator+=(const String &string) {
    for (unsigned short i = 0; i < width_; ++i) {
        array_[i] += string.array_[i];
    }
    return *this;
}

String &String::operator*=(const String &string) {
    for (unsigned short i = 0; i < width_; ++i) {
        array_[i] *= string.array_[i];
    }
    return *this;
}

String &String::operator-=(const String &string) {
    for (unsigned short i = 0; i < width_; ++i) {
        array_[i] -= string.array_[i];
    }
    return *this;
}

String operator+(const String &string_1, const String &string_2) {
    String string(string_1);
    string += string_2;
    return string;
}

String operator*(const String &string_1, const String &string_2) {
    String string(string_1);
    string *= string_2;
    return string;
}

String operator-(const String &string_1, const String &string_2) {
    String string(string_1);
    string -= string_2;
    return string;
}

// Vector

Vector &Vector::operator+=(const Vector &vector) {
    for (unsigned short i = 0; i < height_; ++i) {
        array_[i] += vector.array_[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &vector) {
    for (unsigned short i = 0; i < height_; ++i) {
        array_[i] -= vector.array_[i];
    }
    return *this;
}

Vector &Vector::operator*=(const Vector &vector) {
    for (unsigned short i = 0; i < height_; ++i) {
        array_[i] *= vector.array_[i];
    }
    return *this;
}

Vector operator+(const Vector &vector_1, const Vector &vector_2) {
    Vector vector(vector_1);
    vector += vector_2;
    return vector;
}

Vector operator*(const Vector &vector_1, const Vector &vector_2) {
    Vector vector(vector_1);
    vector *= vector_2;
    return vector;
}

Vector operator-(const Vector &vector_1, const Vector &vector_2) {
    Vector vector(vector_1);
    vector -= vector_2;
    return vector;
}
