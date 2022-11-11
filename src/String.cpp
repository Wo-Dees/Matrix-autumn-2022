#include "../api/String.hpp"

String::String(unsigned short width) : width_(width), array_(width, 0) {

}

String::String(unsigned short width, double number) : width_(width), array_(width, number) {

}

String::String(const String &string) : width_(string.width_), array_(string.array_) {

}

String::String(const std::vector<double> &vector) : width_(vector.size()), array_(vector) {

}

String::String(const Matrix &matrix) : String(matrix.GetString(0)) {

}

double String::operator[](unsigned short i) const {
    return array_[i];
}

double &String::operator[](unsigned short i) {
    return array_[i];
}

Vector String::Transpose() {
    return Vector(array_);
}
