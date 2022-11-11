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

unsigned short String::Size() const {
    return array_.size();
}

bool operator==(const String &string_1, const String &string_2) {
    for (unsigned short i = 0; i < string_1.Size(); ++i) {
        if (string_1[i] != string_2[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const String& string_1, const String& string_2) {
    return !(string_1 == string_2);
}
