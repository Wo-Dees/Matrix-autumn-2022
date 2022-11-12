#include "../api/Matrix.hpp"

std::vector<double> Matrix::GetDiagonal() const {
    std::vector<double> vector;
    for (unsigned short i = 0; i < std::min(height_, width_); ++i) {
        vector.emplace_back(matrix_[i][i]);
    }
    return vector;
}

String Matrix::GetString(unsigned short i) const {
    return String(matrix_[i]);
}

Vector Matrix::GetColumn(unsigned short i) const {
    std::vector<double> vector;
    for (unsigned short j = 0; j < height_; ++j) {
        vector.emplace_back(matrix_[j][i]);
    }
    return Vector(vector);
}

std::pair<unsigned short, unsigned short> Matrix::GetSize() const {
    return std::pair<unsigned short, unsigned short>(height_, width_);
}
