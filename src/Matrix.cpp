#include "../api/Matrix.hpp"

// Constructors
Matrix::Matrix(unsigned short height, unsigned short width) : height_(height), width_(width) {
    matrix_.resize(height);
    for (auto& vec : matrix_) {
        vec.resize(width, 0);
    }
}

Matrix::Matrix(unsigned short height, unsigned short width, double number) : height_(height), width_(width) {
    matrix_.resize(height);
    for (auto& vec : matrix_) {
        vec.resize(width, number);
    }
}

Matrix::Matrix(const Vector &vector) : height_(vector.height_), width_(1) {
    matrix_.resize(height_, std::vector<double>(1));
    for (unsigned short i = 0; i < height_; ++i) {
        matrix_[i][0] = vector[i];
    }
}

Matrix::Matrix(const String &string) : height_(1), width_(string.width_) {
    matrix_.resize(1, std::vector<double>(width_));
    for (unsigned short i = 0; i < width_; ++i) {
        matrix_[0][i] = string[i];
    }
}

Matrix::Matrix(const Matrix &matrix) : height_(matrix.height_), width_(matrix.width_) {
    for (unsigned short i = 0; i < height_; ++i) {
        matrix_.emplace_back(std::vector<double>(matrix.matrix_[i]));
    }
}

Matrix::Matrix(const std::vector<std::vector<double>> &matrix) : height_(matrix.size()), width_(matrix[0].size()) {
    for (unsigned short i = 0; i < height_; ++i) {
        matrix_.emplace_back(std::vector<double>(matrix[i]));
    }
}

Matrix::Matrix(const Vector &vector, unsigned short n) : height_(vector.height_), width_(n), matrix_(n, vector.array_) {

}

Matrix::Matrix(const String &string, unsigned short n) : height_(n), width_(string.width_), matrix_(n, string.array_){

}

// Operators []
String Matrix::operator[](unsigned short i) const {
    return GetString(i);
}

std::vector<double> &Matrix::operator[](unsigned short i) {
    return matrix_[i];
}

// Matrix actions
Matrix Matrix::Transpose() const {
    Matrix matrix(width_, height_);
    for (unsigned short i = 0; i < width_; ++i) {
        for (unsigned short j = 0; j < height_; ++j) {
            matrix.matrix_[i][j] = matrix_[j][i];
        }
    }
    return matrix;
}

Matrix Matrix::Inverse() const {
    // TODO
    return Matrix(3, 3);
}

double Matrix::GetDeterminant() const {
    // TODO
    return 0;
}