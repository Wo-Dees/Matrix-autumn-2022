#include "../api/Matrix.hpp"
#include <gtest/gtest.h>

void FillMatrixNull(Matrix &matrix) {
    unsigned short h = matrix.GetSize().first;
    unsigned short w = matrix.GetSize().second;

    for (unsigned short i = 0; i < h; ++i) {
        for (unsigned short j = 0; j < w; ++j) {
            matrix[i][j] = i * i;
        }
    }
}

void FillMatrixOne(Matrix &matrix) {
    unsigned short h = matrix.GetSize().first;
    unsigned short w = matrix.GetSize().second;

    for (unsigned short i = 0; i < h; ++i) {
        for (unsigned short j = 0; j < w; ++j) {
            matrix[i][j] = i + j;
        }
    }
}

void FillMatrixTwo(Matrix &matrix) {
    unsigned short h = matrix.GetSize().first;
    unsigned short w = matrix.GetSize().second;

    for (unsigned short i = 0; i < h; ++i) {
        for (unsigned short j = 0; j < w; ++j) {
            matrix[i][j] = i;
        }
    }
}

void FillMatrixThree(Matrix &matrix) {
    unsigned short h = matrix.GetSize().first;
    unsigned short w = matrix.GetSize().second;

    for (unsigned short i = 0; i < h; ++i) {
        for (unsigned short j = 0; j < w; ++j) {
            matrix[i][j] = j;
        }
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Matrix, Scalar) {
    Matrix matrix1(11, 18);
    Matrix matrix2(11, 18);
    Matrix matrix3(11, 18);
    Matrix matrix4(11, 18);
    Matrix matrix5(11, 18);

    FillMatrixNull(matrix5);
    FillMatrixOne(matrix3);
    FillMatrixTwo(matrix2);
    FillMatrixThree(matrix1);

    EXPECT_TRUE(matrix1 + matrix2 == matrix3);
    EXPECT_TRUE(matrix1 - matrix1 == matrix4);
    EXPECT_TRUE(matrix2 * matrix2 == matrix5);

    EXPECT_TRUE((matrix1 += matrix2) == matrix3);
    EXPECT_TRUE((matrix2 *= matrix2) == matrix5);
}

TEST(Vector, scalar) {
    unsigned short len = 1000;

    std::vector<double> vector1(len);
    std::vector<double> vector2(len);
    std::vector<double> vector3(len);
    std::vector<double> vector4(len);

    for (int i = 0; i < len; ++i) {
        vector1[i] = i;
        vector2[i] = -i;
        vector3[i] = i * i;
    }

    Vector vector_1(vector1);
    Vector vector_2(vector2);
    Vector vector_3(vector3);
    Vector vector_4(len, 0);

    EXPECT_TRUE((vector_1 + vector_2) == vector_4);
    EXPECT_TRUE(vector_1 * vector_1 == vector_3);
    EXPECT_TRUE(vector_1 - vector_2 == vector_1 + vector_1);

    EXPECT_TRUE((vector_1 += vector_2) == vector_4);

    vector_1 -= vector_2;

    EXPECT_TRUE((vector_1 *= vector_1) == vector_3);
    EXPECT_TRUE((vector_1 -= vector_2) == (vector_1 += vector_1));
}

TEST(String, scalar) {
    unsigned short len = 1000;

    std::vector<double> vector1(len);
    std::vector<double> vector2(len);
    std::vector<double> vector3(len);
    std::vector<double> vector4(len);

    for (int i = 0; i < len; ++i) {
        vector1[i] = i;
        vector2[i] = -i;
        vector3[i] = i * i;
    }

    String string_1(vector1);
    String string_2(vector2);
    String string_3(vector3);
    String string_4(len);

    EXPECT_TRUE(string_1 + string_2 == string_4);
    EXPECT_TRUE(string_1 * string_1 == string_3);
    EXPECT_TRUE(string_1 - string_2 == string_1 + string_1);

    EXPECT_TRUE((string_1 += string_2) == string_4);

    string_1 -= string_2;

    EXPECT_TRUE((string_1 *= string_1) == string_3);
    EXPECT_TRUE((string_1 -= string_2) == (string_1 += string_1));
}