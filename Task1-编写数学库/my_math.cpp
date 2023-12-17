/*
* 文件名：my_math.cpp
* 作者信息：谢泽浩
* 重构时间：2023-12-16
* 文件内容：计算机图形学使用的数学库
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#include"my_math.h"
namespace XX_XZH {
  Vector3::Vector3() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
    w_ = 1;
  }
  Vector3::Vector3(float x, float y, float z) :x_(x), y_(y), z_(z), w_(1) {}
  Vector3::Vector3(const Vector3& tmp_v3) {
    x_ = tmp_v3.x_;
    y_ = tmp_v3.y_;
    z_ = tmp_v3.z_;
    w_ = tmp_v3.w_;
  }
  Vector3::~Vector3() {}
  float Vector3::GetX()const {
    return x_;
  }
  void Vector3::SetX(float x) {
    x_ = x;
  }
  float Vector3::GetY() const {
    return y_;
  }
  void Vector3::SetY(float y) {
    y_ = y;
  }
  float Vector3::GetZ() const {
    return z_;
  }
  void Vector3::SetZ(float z) {
    z_ = z;
  }
  void Vector3::Normalize() {
    float tmp_result;
    tmp_result = this->Norm();
    this->x_ = this->x_ / tmp_result;
    this->y_ = this->y_ / tmp_result;
    this->z_ = this->z_ / tmp_result;
  }
  float Vector3::Norm() {
    return (float)sqrt(x_ * x_ + y_ * y_ + z_ * z_);
  }
  void Vector3::OutPutVector3() {
    std::cout << "Vector3" << this->GetX() << "," << this->GetY() << "," << this->GetZ() << std::endl;
  }
  Vector3 Vector3::operator=(const Vector3& tmp_v3) {
    this->x_ = tmp_v3.x_;
    this->y_ = tmp_v3.y_;
    this->z_ = tmp_v3.z_;
    this->w_ = tmp_v3.w_;
    return *this;
  }
  float Dot(const Vector3& left_v3, const Vector3& right_v3) {
    float tmp_result;
    tmp_result = left_v3.GetX() * right_v3.GetX() + left_v3.GetY() * right_v3.GetY() + left_v3.GetZ() * right_v3.GetZ();
    return tmp_result;
  }
  Vector3 Cross(const Vector3& left_v3, const Vector3& right_v3) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(left_v3.GetY() * right_v3.GetZ() - right_v3.GetY() * left_v3.GetZ());
    tmp_vector3.SetY(left_v3.GetZ() * right_v3.GetX() - right_v3.GetZ() * left_v3.GetY());
    tmp_vector3.SetZ(left_v3.GetX() * right_v3.GetY() - right_v3.GetX() * left_v3.GetY());
    return tmp_vector3;
  }
  Vector3 Lerp(const Vector3& from, const Vector3& to, float t) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(from.GetX() + t * (to.GetX() - from.GetX()));
    tmp_vector3.SetY(from.GetY() + t * (to.GetY() - from.GetY()));
    tmp_vector3.SetZ(from.GetZ() + t * (to.GetZ() - from.GetZ()));
    return tmp_vector3;
  }
  Vector3 operator+(const Vector3& left_v3, const Vector3& right_v3) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(left_v3.GetX() + right_v3.GetX());
    tmp_vector3.SetY(left_v3.GetY() + right_v3.GetY());
    tmp_vector3.SetZ(left_v3.GetZ() + right_v3.GetZ());
    return tmp_vector3;
  }
  Vector3 operator-(const Vector3& left_v3, const Vector3& right_v3) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(left_v3.GetX() - right_v3.GetX());
    tmp_vector3.SetY(left_v3.GetY() - right_v3.GetY());
    tmp_vector3.SetZ(left_v3.GetZ() - right_v3.GetZ());
    return tmp_vector3;
  }
  float operator*(const Vector3& tmp_v1, const Vector3& tmp_v2) {
    float tmp_result;
    tmp_result = tmp_v1.GetX() * tmp_v2.GetX() + tmp_v1.GetY() * tmp_v2.GetY() + tmp_v1.GetZ() * tmp_v2.GetZ();
    return tmp_result;
  }
  Vector3 operator*(const Vector3& left_v3, float right) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(left_v3.GetX() * right);
    tmp_vector3.SetY(left_v3.GetY() * right);
    tmp_vector3.SetZ(left_v3.GetZ() * right);
    return tmp_vector3;
  }
  Vector3 operator*(float left, const Vector3& right_v3) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(right_v3.GetX() * left);
    tmp_vector3.SetY(right_v3.GetY() * left);
    tmp_vector3.SetZ(right_v3.GetZ() * left);
    return tmp_vector3;
  }
  Vector3 operator/(const Vector3& left_v3, float right) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(left_v3.GetX() / right);
    tmp_vector3.SetY(left_v3.GetY() / right);
    tmp_vector3.SetZ(left_v3.GetZ() / right);
    return tmp_vector3;
  }
  bool operator==(const Vector3& left_v3, const Vector3& right_v3) {
    return left_v3.GetX() == right_v3.GetX() && left_v3.GetY() == right_v3.GetY() && left_v3.GetZ() == right_v3.GetZ();
  }
  bool operator!=(const Vector3& left_v3, const Vector3& right_v3) {
    return !(left_v3.GetX() == right_v3.GetX() && left_v3.GetY() == right_v3.GetY() && left_v3.GetZ() == right_v3.GetZ());
  }
  Vector2::Vector2() {
    x_ = 0;
    y_ = 0;
    w_ = 0;
  }
  Vector2::Vector2(float x, float y):x_(x),y_(y),w_(1){}
  Vector2::Vector2(const Vector2& tmp_v2) {
    x_ = tmp_v2.x_;
    y_ = tmp_v2.y_;
    w_ = tmp_v2.w_;
  }
  Vector2::~Vector2(){}
  float Vector2::GetX()const {
    return x_;
  }
  void Vector2::SetX(float x) {
    x_ = x;
  }
  float Vector2::GetY()const {
    return y_;
  }
  void Vector2::SetY(float y) {
    y_ = y;
  }
  void Vector2::Normalize() {
    float tmp_num = this->Norm();
    this->x_ = x_ / tmp_num;
    this->y_ = y_ / tmp_num;
  }
  float Vector2::Norm() {
    return (float)sqrt(x_ * x_ + y_ * y_);
  }
  void Vector2::OutPutVector2() {
    std::cout << "Vector2:" << this->GetX() << "," << this->GetY() << std::endl;
  }
  Vector2 Vector2::operator=(const Vector2& tmp_v2) {
    this->x_ = tmp_v2.x_;
    this->y_ = tmp_v2.y_;
    return *this;
  }
  float Dot(const Vector2& left_v2, const Vector2& right_v2) {
    return left_v2.GetX() * right_v2.GetX() + left_v2.GetY() * right_v2.GetY();
  }
  float Cross(const Vector2& left_v2, const Vector2& right_v2) {
    return left_v2.GetX() * right_v2.GetY() - left_v2.GetX() * right_v2.GetY();
  }
  Vector2 Lerp(const Vector2& from, const Vector2& to, float t) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(from.GetX() + t * (to.GetX() - from.GetX()));
    tmp_vector2.SetY(from.GetY() + t * (to.GetY() - from.GetY()));
    return tmp_vector2;
  }
  Vector2 operator+(const Vector2& left_v2, const Vector2& right_v2) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(left_v2.GetX() + right_v2.GetX());
    tmp_vector2.SetY(left_v2.GetY() + right_v2.GetY());
    return tmp_vector2;
  }
  Vector2 operator-(const Vector2& left_v2, const Vector2& right_v2) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(left_v2.GetX() - right_v2.GetX());
    tmp_vector2.SetY(left_v2.GetY() - right_v2.GetY());
    return tmp_vector2;
  }
  float operator*(const Vector2& left_v2, const Vector2& right_v2) {
    return left_v2.GetX() * right_v2.GetX() + left_v2.GetY() * right_v2.GetY();
  }
  Vector2 operator*(const Vector2& left_v2, float right) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(left_v2.GetX() * right);
    tmp_vector2.SetY(left_v2.GetY() * right);
    return tmp_vector2;
  }
  Vector2 operator*(float left, const Vector2& right_v2) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(right_v2.GetX() * left);
    tmp_vector2.SetY(right_v2.GetY() * left);
    return tmp_vector2;
  }
  Vector2 operator/(const Vector2& left_v2, float right) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(left_v2.GetX() / right);
    tmp_vector2.SetY(left_v2.GetY() / right);
    return tmp_vector2;
  }
  bool operator==(const Vector2& left_v2, const Vector2& right_v2) {
    return left_v2.GetX() == right_v2.GetX() && left_v2.GetY() == right_v2.GetY();
  }
  bool operator!=(const Vector2& left_v2, const Vector2& right_v2) {
    return !(left_v2.GetX() == right_v2.GetX() && left_v2.GetY() == right_v2.GetY());
  }
  Matrix::Matrix() {
    matrix_order_ = 4;
    std::vector<int> tmp_vector;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        tmp_vector.push_back(0);
      }
      matrix_.push_back(tmp_vector);
    }
  }
  Matrix::Matrix(const Matrix& tmp_matrix) {
    matrix_ = tmp_matrix.matrix_;
    matrix_order_ = tmp_matrix.matrix_order_;
  }
  Matrix::~Matrix() {
  }
  int Matrix::GetMatrixOrder() const
  {
    return this->matrix_order_;
  }
  void Matrix::Identity() {
    matrix_[0][0] = 1; matrix_[0][1] = 0; matrix_[0][2] = 0; matrix_[0][3] = 0;
    matrix_[1][0] = 0; matrix_[1][1] = 1; matrix_[1][2] = 0; matrix_[1][3] = 0;
    matrix_[2][0] = 0; matrix_[2][1] = 0; matrix_[2][2] = 1; matrix_[2][3] = 0;
    matrix_[3][0] = 0; matrix_[3][1] = 0; matrix_[3][2] = 0; matrix_[3][3] = 1;
  }
  void Matrix::OutPutMatrix() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        std::cout << matrix_[i][j] << " ";
      }
      std::cout << std::endl; 
    }
  }
  Matrix operator*(const Matrix& m1, const Matrix& m2)
  {
    Matrix tmp_matrix;
    int tmp_num;
    assert(m1.GetMatrixOrder() == m2.GetMatrixOrder());
    tmp_num = m1.GetMatrixOrder();
    for (int i = 0; i < tmp_num; i++) {
      for (int j = 0; j < tmp_num; j++) {
        for (int k = 0; k < tmp_num; k++) {
          tmp_matrix.matrix_[i][j] += m1.matrix_[i][k] * m2.matrix_[k][j];
        }
      }
    }
    return tmp_matrix;
  }
}
