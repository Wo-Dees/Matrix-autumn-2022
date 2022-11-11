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

Matrix::Matrix(const Vector &vector, unsigned short n) : height_(vector.height_), width_(n) {
    matrix_.resize(height_, std::vector<double>(n, 0));
    for (unsigned short i = 0; i < height_; ++i) {
        for (unsigned short j = 0; j < width_; ++j) {
            matrix_[i][j] = vector[i];
        }
    }
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

Matrix Matrix::Inverse() const { // for matrix 2 on 2
    Matrix matrix(2, 2);
    std::swap(matrix[0][0], matrix[1][1]);
    matrix[0][1] *= -1;
    matrix[1][0] *= -1;
    matrix *= 1 / matrix.GetDeterminant();
    return matrix;
}

double Matrix::GetDeterminant() const {
    Matrix matrix(matrix_);
    for (unsigned short i = 0; i < width_ - 1; ++i) {
        if (matrix[i][i] == 0) {
            for (unsigned short j = i + 1; i < width_; ++j) {
               if (matrix[j][i] != 0) {
                   for (unsigned short k = i; k < width_; ++k) {
                       std::swap(matrix[i][k], matrix[j][k]);
                   }
                   break;
               }
            }
        }
        for (unsigned short j = i + 1; i < width_; ++j) {
            for (unsigned short k = i; k < width_; ++k) {
                matrix[j][k] -= matrix[i][k] * matrix[j][i] / matrix[i][i];
            }
        }
    }
    double det = 1;
    for (unsigned short i = 0; i < width_ - 1; ++i) {
        det *= matrix[i][i];
    }
    return det;
}

bool operator==(const Matrix &matrix_1, const Matrix &matrix_2) {
    unsigned short h = matrix_1.GetSize().first;
    unsigned short w = matrix_1.GetSize().second;
    for (unsigned short i = 0; i < h; ++i) {
        for (unsigned short j = 0; j < w; ++j) {
            if (matrix_1[i][j] != matrix_2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Matrix &maxtix_1, const Matrix &maxtix_2) {
    return !(maxtix_1 == maxtix_2);
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
    unsigned short h = matrix.GetSize().first;
    unsigned short w = matrix.GetSize().second;
    for (unsigned short i = 0; i < h; ++i) {
        for (unsigned short j = 0; j < w; ++j) {
            os << matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
