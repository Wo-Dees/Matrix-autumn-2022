#include "../api/Matrix.hpp"
#include <gtest/gtest.h>

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

TEST(Matrix, Broadcasting) {
    Matrix matrix_1(100, 100);
    Matrix matrix_2(100, 100);

    FillMatrixOne(matrix_1);

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            matrix_2[i][j] += (i + j + 131);
        }
    }

    EXPECT_TRUE(matrix_1 + 131 == matrix_2);
    EXPECT_TRUE(matrix_1 == matrix_2 - 131);
    EXPECT_TRUE(matrix_2 != matrix_1);

    std::vector<double> vector1(100);
    std::vector<double> vector2(100);
    std::vector<double> vector3(100, 1);

    for (int i = 0; i < 100; ++i) {
        vector1[i] = i;
        vector2[i] = i + 13;
    }

    EXPECT_TRUE(String(vector1) + 13 == String(vector2));
    EXPECT_TRUE(String(vector1) == String(vector2) - 13);

    EXPECT_TRUE(Vector(vector1) + 13 == Vector(vector2));
    EXPECT_TRUE(Vector(vector1) == Vector(vector2) - 13);

    Matrix matrix3(100, 100, 1);

    EXPECT_TRUE(Vector(vector3) * matrix3 == matrix3);
    EXPECT_TRUE(matrix3 == matrix3 * String(vector3));
}

