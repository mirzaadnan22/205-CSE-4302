#include <iostream>
using namespace std;

class Matrix3D {
private:
  float matrix[3][3];
  float incStep;
  static int count;

public:
  Matrix3D(float arr[3][3]) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        matrix[i][j] = arr[i][j];
      }
    }
    incStep = 1;
    count++;
  }

  float det() const {
    float a = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]);
    float b = matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    float c = matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[2][0] * matrix[1][1]);

    return a - b + c;
  }

  Matrix3D inverse() const {
    float determinant = det();

    float invDet = 1.0f / determinant;

    float inv[3][3];

    inv[0][0] = (matrix[1][1] * matrix[2][2] - matrix[2][1] * matrix[1][2]) * invDet;
    inv[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) * invDet;
    inv[0][2] = (matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2]) * invDet;
    inv[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) * invDet;
    inv[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) * invDet;
    inv[1][2] = (matrix[1][0] * matrix[0][2] - matrix[0][0] * matrix[1][2]) * invDet;
    inv[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) * invDet;
    inv[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) * invDet;
    inv[2][2] = (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]) * invDet;

    return Matrix3D(inv);
  }

  void setIncrement(float inc) {
    if (count == 0) {
      if (inc >= 0) {
        incStep = inc;
      }
    }
  }

  Matrix3D* getMatrix() {
    return this;
  }

  void increment() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        matrix[i][j] += incStep;
      }
    }
  }

  Matrix3D operator+(const Matrix3D mat1) const {
    float arr[3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        arr[i][j] = matrix[i][j] + mat1.matrix[i][j];
      }
    }

    return Matrix3D(arr);
  }

  Matrix3D operator-(const Matrix3D mat1) const {
    float arr[3][3];
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        arr[i][j] = matrix[i][j] - mat1.matrix[i][j];
      }
    }

    return Matrix3D(arr);
  }

  Matrix3D operator*(const Matrix3D& mat1) const {
    float arr[3][3] = { 0 };
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
          arr[i][j] += matrix[i][k] * mat1.matrix[k][j];
        }
      }
    }
    return Matrix3D(arr);
  }

  bool operator>(const Matrix3D& mat1) const {
    return det() > mat1.det();
  }

  bool operator<(const Matrix3D& mat1) const {
    return det() < mat1.det();
  }

  bool operator>=(const Matrix3D& mat1) const {
    return det() >= mat1.det();
  }

  bool operator<=(const Matrix3D& mat1) const {
    return det() <= mat1.det();
  }

  bool operator==(const Matrix3D& mat1) const {
    return det() == mat1.det();
  }

  bool operator!=(const Matrix3D& mat1) const {
    return det() != mat1.det();
  }

  void print() const {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << "\n";
    }
  }
};

int Matrix3D::count = 0;

int main() {
  float arr1[3][3] = { {4, 7, 2}, {3, 2, 1}, {1, 1, 1} };
  float arr2[3][3] = { {1, 1, 1}, {4, 7, 2}, {3, 2, 1} };
  Matrix3D mat1(arr1);
  Matrix3D mat2(arr2);

  Matrix3D mat3 = mat1 + mat2;
  Matrix3D mat4 = mat1 * mat2;
  mat3.print();
  mat4.print();

  Matrix3D mat1Inv = mat1.inverse();
  mat1Inv.print();
}