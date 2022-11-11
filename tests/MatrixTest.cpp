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

TEST(Matrix, Constructors) {

  unsigned short h = 10;
  unsigned short w = 15;

  std::vector<std::vector<double>> vector(10);
  for (auto &i : vector) {
    i.resize(15, 0);
  }
  Matrix matrix_1(h, w);
  Matrix matrix_2(h, w, 0);
  Matrix matrix_3(matrix_2);
  Matrix matrix_4(vector);
  Matrix matrix_5(1, w);
  Matrix matrix_6(h, 1);

  FillMatrixOne(matrix_5);
  FillMatrixOne(matrix_6);

  std::vector<double> vector_h_1(h);
  for (size_t i = 0; i < h; ++i) {
    vector_h_1[i] = i;
  }

  std::vector<double> vector_w_1(w);
  for (size_t i = 0; i < w; ++i) {
    vector_w_1[i] = i;
  }

  Matrix matrix_7(h, w);
  Matrix matrix_8(h, w);
  FillMatrixTwo(matrix_7);
  FillMatrixThree(matrix_8);

  EXPECT_TRUE(matrix_1 == matrix_2);
  EXPECT_TRUE(matrix_3 == matrix_2);
  EXPECT_TRUE(matrix_3 == matrix_4);
  EXPECT_TRUE(matrix_5 == Matrix(String(vector_w_1)));
  EXPECT_TRUE(matrix_6 == Matrix(Vector(vector_h_1)));
  EXPECT_TRUE(Matrix(String(vector_w_1), h) == matrix_8);
  EXPECT_TRUE(Matrix(Vector(vector_h_1), w) == matrix_7);
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
