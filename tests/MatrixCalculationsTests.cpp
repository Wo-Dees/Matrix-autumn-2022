#include "../api/Matrix.hpp"
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(Matrix, Matrix) {
    Matrix matrix_1(100, 10, 103);
    Matrix matrix_2(10, 100, 103);
    Matrix matrix_3(100, 100, 103 * 103 * 10);
    Matrix matrix_4(10, 10, 103 * 103 * 100);

    EXPECT_TRUE(matrix_1 % matrix_2 == matrix_3);
    EXPECT_TRUE(matrix_2 % matrix_1 == matrix_4);

    Vector vector_1(100, 1);
    Vector vector_2(10, 0);

    EXPECT_TRUE(matrix_2 % vector_1 == Vector(10, 103 * 100));
    EXPECT_TRUE(matrix_1 % vector_2 == Vector(100, 0));

    String string_1(100, 1);
    String string_2(10, 0);

    EXPECT_TRUE(string_1 % matrix_1 == String(10, 103 * 100));
    EXPECT_TRUE(string_2 % matrix_2 == String(100, 0));
}