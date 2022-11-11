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

TEST(Matrix, Get) {

  unsigned short h = 10;
  unsigned short w = 15;

  Matrix matrix(h, w);
  FillMatrixOne(matrix);

  std::vector<double> vector_h_1(h);
  for (size_t i = 0; i < h; ++i) {
    vector_h_1[i] = i;
  }

  std::vector<double> vector_w_1(w);
  for (size_t i = 0; i < w; ++i) {
    vector_w_1[i] = i;
  }

  std::vector<double> vector_h_2(h);
  for (size_t i = 0; i < h; ++i) {
    vector_h_2[i] = i + 7;
  }

  std::vector<double> vector_w_2(w);
  for (size_t i = 0; i < w; ++i) {
    vector_w_2[i] = i + 4;
  }

  std::vector<double> diag(std::min(h, w));
  for (size_t i = 0; i < std::min(h, w); ++i) {
    diag[i] = i * 2;
  }

  EXPECT_TRUE(matrix.GetColumn(0) == Vector(vector_h_1));
  EXPECT_TRUE(matrix.GetString(0) == String(vector_w_1));
  EXPECT_TRUE(matrix.GetColumn(7) == Vector(vector_h_2));
  EXPECT_TRUE(matrix.GetString(4) == String(vector_w_2));
  EXPECT_TRUE(matrix.GetDiagonal() == diag);
}