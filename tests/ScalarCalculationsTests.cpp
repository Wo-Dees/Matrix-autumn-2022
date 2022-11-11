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
}