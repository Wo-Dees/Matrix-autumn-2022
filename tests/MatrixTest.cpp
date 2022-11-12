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

TEST(Matrix, Operations) {
    std::vector<std::vector<double>> vector(10);
    for (auto &i : vector) {
        i.resize(15, 0);
    }
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            vector[i][j] = i + j;
        }
    }
    Matrix matrix(vector);
    EXPECT_TRUE(matrix[3][3] == 6);
    EXPECT_TRUE(matrix[3][7] == 10);
    EXPECT_TRUE(matrix[9][3] == 12);
}

TEST(Matrix, MatrixOperations) {

    std::vector<std::vector<double>> vector(10);
    for (auto &i : vector) {
        i.resize(15, 0);
    }

    std::vector<std::vector<double>> vector_(15);
    for (auto &i : vector_) {
        i.resize(10, 0);
    }

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 15; ++j) {
            vector[i][j] = i + j;
            vector_[j][i] = i + j;
        }
    }

    Matrix matrix1(vector);
    Matrix matrix2(vector_);

    EXPECT_TRUE(matrix1.Transpose() == matrix2);
    EXPECT_TRUE(matrix2.Transpose() == matrix1);
}

TEST(Matrix, Determinant) {

    Matrix matrix1(3, 3);
    matrix1[0][0] = 3;
    matrix1[1][1] = 3;
    matrix1[2][2] = 3;

    EXPECT_TRUE(matrix1.GetDeterminant() - 27 < 0.001);

    Matrix matrix2(3, 3);
    matrix2[0][0] = 71;
    matrix2[0][1] = 15;
    matrix2[0][2] = 17;
    matrix2[1][0] = 1;
    matrix2[1][1] = 54;
    matrix2[1][2] = 6;
    matrix2[2][0] = 3;
    matrix2[2][1] = 5;
    matrix2[2][2] = 6;

    EXPECT_TRUE(matrix2.GetDeterminant() - 18385 < 0.001);

    Matrix matrix3(3, 3);
    matrix3[0][0] = 71;
    matrix3[0][1] = 15;
    matrix3[0][2] = 17;
    matrix3[1][0] = 1;
    matrix3[1][1] = 0;
    matrix3[1][2] = 6;
    matrix3[2][0] = 3;
    matrix3[2][1] = 5;
    matrix3[2][2] = 6;

    EXPECT_TRUE(matrix3.GetDeterminant() + 1865 < 0.001);
}
