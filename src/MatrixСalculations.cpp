#include "../api/Matrix.hpp"

Matrix &Matrix::operator%=(const Matrix &maxtix) {
    unsigned short h = this->height_;
    unsigned short w = maxtix.width_;
    std::vector<std::vector<double>> mat(h);
    for (unsigned short i = 0; i < h; ++i) {
        mat.emplace_back(std::vector<double>(w, 0));
        for (unsigned short j = 0; j < w; ++j) {
            for (unsigned short k = 0; k < width_; ++k) {
                mat[i][j] += matrix_[i][k] * maxtix.matrix_[k][j];
            }
        }
    }
    matrix_ = std::move(mat);
    return *this;
}

Matrix operator%(const Matrix &maxtix_1, const Matrix &maxtix_2) {
    Matrix matrix(maxtix_1);
    matrix %= maxtix_2;
    return matrix;
}

Vector operator%(const Matrix &maxtix, const Vector &vector) {
    Matrix mat(maxtix);
    mat %= Matrix(vector);
    return Vector(mat);
}

String operator%(const String &string, const Matrix &maxtix) {
    Matrix mat(string);
    mat %= maxtix;
    return String(mat);
}