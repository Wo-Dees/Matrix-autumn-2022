#include "../api/String.hpp"
#include <gtest/gtest.h>

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(String, Constructors) {
    unsigned short len = 100;

    String string_1(len);
    String string_2(len, 83);
    String string_3(string_2);

    std::vector<double> vector(len);
    for (size_t i = 0; i < len; ++i) {
        vector[i] = i;
    }

    String string_4(vector);
    Vector vector_1(vector);

    String string_5(len, 55);
    for (size_t i = 0; i < len; ++i) {
        string_5[i] = i;
    }

    EXPECT_TRUE(string_2 == string_3);
    EXPECT_TRUE(string_1 != string_3);
    EXPECT_TRUE(string_4.Transpose() == vector_1);
    EXPECT_TRUE(string_4 == string_5);
    EXPECT_TRUE(string_4.Size() == len);
}
