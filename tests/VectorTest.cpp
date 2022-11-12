#include "../api/Vector.hpp"
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(String, Constructors) {
    unsigned short len = 100;

    Vector vector_1(len);
    Vector vector_2(len, 83);
    Vector vector_3(vector_2);

    std::vector<double> vector(len);
    for (size_t i = 0; i < len; ++i) {
        vector[i] = i;
    }

    Vector vector_4(vector);
    String string_1(vector);

    Vector vector_5(len, 55);
    for (size_t i = 0; i < len; ++i) {
        vector_5[i] = i;
    }

    EXPECT_TRUE(vector_2 == vector_3);
    EXPECT_TRUE(vector_1 != vector_3);
    EXPECT_TRUE(vector_4.Transpose() == string_1);
    EXPECT_TRUE(vector_4 == vector_5);
    EXPECT_TRUE(vector_4.Size() == len);
}
