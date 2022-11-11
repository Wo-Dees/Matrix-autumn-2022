#include "../api/Vector.hpp"

Vector::Vector(unsigned short height) :  height_(height), array_(height, 0) {

}

Vector::Vector(unsigned short height, double number) : height_(height), array_(height, number) {

}

Vector::Vector(const Vector &vector) : height_(vector.height_), array_(vector.array_) {

}

Vector::Vector(const std::vector<double> &vector) : height_(vector.size()), array_(vector) {

}

Vector::Vector(const Matrix &matrix) : Vector(matrix.GetColumn(0)) {

}

double Vector::operator[](unsigned short i) const {
    return array_[i];
}

double &Vector::operator[](unsigned short i) {
    return array_[i];
}

String Vector::Transpose() {
    return String(array_);
}
