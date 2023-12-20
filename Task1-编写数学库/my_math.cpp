/*
* 文件名：my_math.cpp
* 作者信息：谢泽浩
* 重构时间：2023-12-16
* 文件内容：计算机图形学使用的数学库
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#define _USE_MATH_DEFINES
#include"my_math.h"
namespace XX_XZH {
  Vector3::Vector3() {
    x_ = 1;
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
  Vector3::~Vector3() {
  }
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
  float Vector3::GetW() const
  {
    return w_;
  }
  void Vector3::SetW(float w)
  {
    w_ = w;
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
  void Vector3::ExchangeXY()
  {
    float tmp = x_;
    x_ = y_;
    y_ = tmp;
  }
  Vector3& Vector3::operator=(const Vector3& tmp_v3) {
    this->x_ = tmp_v3.x_;
    this->y_ = tmp_v3.y_;
    this->z_ = tmp_v3.z_;
    this->w_ = tmp_v3.w_;
    return *this;
  }
  Vector3::operator Vector2()
  {
    return Vector2(x_, y_);
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
    tmp_vector3.SetW(0);
    return tmp_vector3;
  }
  Vector3 Lerp(const Vector3& from, const Vector3& to, float t) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(from.GetX() + t * (to.GetX() - from.GetX()));
    tmp_vector3.SetY(from.GetY() + t * (to.GetY() - from.GetY()));
    tmp_vector3.SetZ(from.GetZ() + t * (to.GetZ() - from.GetZ()));
    tmp_vector3.SetW(1);
    return tmp_vector3;
  }
  Vector3 operator+(const Vector3& left_v3, const Vector3& right_v3) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(left_v3.GetX() + right_v3.GetX());
    tmp_vector3.SetY(left_v3.GetY() + right_v3.GetY());
    tmp_vector3.SetZ(left_v3.GetZ() + right_v3.GetZ());
    tmp_vector3.SetW(left_v3.GetW() + right_v3.GetW());
    return tmp_vector3;
  }
  Vector3 operator-(const Vector3& left_v3, const Vector3& right_v3) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(left_v3.GetX() - right_v3.GetX());
    tmp_vector3.SetY(left_v3.GetY() - right_v3.GetY());
    tmp_vector3.SetZ(left_v3.GetZ() - right_v3.GetZ());
    tmp_vector3.SetW(left_v3.GetW() - right_v3.GetW());
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
    tmp_vector3.SetW(left_v3.GetW());
    return tmp_vector3;
  }
  Vector3 operator*(float left, const Vector3& right_v3) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(right_v3.GetX() * left);
    tmp_vector3.SetY(right_v3.GetY() * left);
    tmp_vector3.SetZ(right_v3.GetZ() * left);
    tmp_vector3.SetW(right_v3.GetW());
    return tmp_vector3;
  }
  Vector3 operator/(const Vector3& left_v3, float right) {
    Vector3 tmp_vector3;
    tmp_vector3.SetX(left_v3.GetX() / right);
    tmp_vector3.SetY(left_v3.GetY() / right);
    tmp_vector3.SetZ(left_v3.GetZ() / right);
    tmp_vector3.SetW(left_v3.GetW());
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
    w_ = 1;
  }
  Vector2::Vector2(float x, float y):x_(x),y_(y),w_(1){}
  Vector2::Vector2(const Vector2& tmp_v2) {
    x_ = tmp_v2.x_;
    y_ = tmp_v2.y_;
    w_ = tmp_v2.w_;
  }
  Vector2::~Vector2(){
  }
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
  float Vector2::GetW() const
  {
    return w_;
  }
  void Vector2::SetW(float w)
  {
    w_ = w;
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
  Vector2 Vector2::ExchangeXY()
  {
    return Vector2(y_, x_);
  }
  Vector2 Vector2::operator=(const Vector2& tmp_v2) {
    this->x_ = tmp_v2.x_;
    this->y_ = tmp_v2.y_;
    this->w_ = tmp_v2.w_;
    return *this;
  }
  Vector2::operator Vector3()
  {
    return Vector3(x_, y_, 0);
  }
  float Dot(const Vector2& left_v2, const Vector2& right_v2) {
    return left_v2.GetX() * right_v2.GetX() + left_v2.GetY() * right_v2.GetY();
  }
  float Cross(const Vector2& left_v2, const Vector2& right_v2) {
    return left_v2.GetX() * right_v2.GetY() - left_v2.GetY() * right_v2.GetX();
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
    tmp_vector2.SetW(left_v2.GetW() + right_v2.GetW());
    return tmp_vector2;
  }
  Vector2 operator-(const Vector2& left_v2, const Vector2& right_v2) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(left_v2.GetX() - right_v2.GetX());
    tmp_vector2.SetY(left_v2.GetY() - right_v2.GetY());
    tmp_vector2.SetW(left_v2.GetW() - right_v2.GetW());
    return tmp_vector2;
  }
  float operator*(const Vector2& left_v2, const Vector2& right_v2) {
    return left_v2.GetX() * right_v2.GetX() + left_v2.GetY() * right_v2.GetY();
  }
  Vector2 operator*(const Vector2& left_v2, float right) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(left_v2.GetX() * right);
    tmp_vector2.SetY(left_v2.GetY() * right);
    tmp_vector2.SetW(left_v2.GetW());
    return tmp_vector2;
  }
  Vector2 operator*(float left, const Vector2& right_v2) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(right_v2.GetX() * left);
    tmp_vector2.SetY(right_v2.GetY() * left);
    tmp_vector2.SetW(right_v2.GetW());
    return tmp_vector2;
  }
  Vector2 operator/(const Vector2& left_v2, float right) {
    Vector2 tmp_vector2;
    tmp_vector2.SetX(left_v2.GetX() / right);
    tmp_vector2.SetY(left_v2.GetY() / right);
    tmp_vector2.SetW(left_v2.GetW());
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
    std::vector<float> tmp_vector;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i == j) {
          tmp_vector.push_back(1);
        }
        tmp_vector.push_back(0);
      }
      matrix_.push_back(tmp_vector);
    }
  }
  Matrix::Matrix(int order)
  {
    matrix_order_ = order;
    std::vector<float> tmp_vector;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (i == j) {
          tmp_vector.push_back(1);
        }
        tmp_vector.push_back(0);
      }
      matrix_.push_back(tmp_vector);
    }
  }
  Matrix::Matrix(const Matrix& tmp_matrix) {
    matrix_ = tmp_matrix.matrix_;
    matrix_order_ = tmp_matrix.matrix_order_;
  }
  /*Model矩阵*/

  /*View矩阵
  * 通常情况下，up是指向上的，即(0,1,0)
  * 1，我们需要根据两个点的坐标，创建摄像头的位置坐标，也是“指向”的起点坐标
  * 2，创建摄像机的结尾坐标，即“指向”的结尾坐标
  * 3，做差，得到“指向”就是方向Z轴，单位化
  * 4，自定义一个工具向量
  * 5，工具向量和Z轴叉乘得到X轴，单位化
  * 6，Z 叉乘 X 得到 Y，单位化
  * 7，摄像机看的方向是-Z轴
  * 8，将相机坐标系移动至原点，可知ViewTranslation矩阵
  * 9，将相机坐标系旋转到正确的方向，可知ViewRotation矩阵
  */
  void Matrix::ViewMatrix(float pos_x, float pos_y, float pos_z, float target_x, float target_y, float target_z, float up_x, float up_y, float up_z){
    Identity();
    Vector3 camera_start_position(pos_x, pos_y, pos_z);
    Vector3 camera_end_position(target_x, target_y, target_z);
    Vector3 camera_z = camera_end_position - camera_start_position;
    camera_z.Normalize();
    Vector3 tmp_direction = Vector3(up_x, up_y, up_z);
    Vector3 camera_x = Cross(tmp_direction, camera_z);
    camera_x.Normalize();
    Vector3 camera_y = Cross(camera_z, camera_x);
    camera_y.Normalize();
    Matrix tmp_camera_translation = Matrix();
    tmp_camera_translation.matrix_[0][3] = -pos_x;
    tmp_camera_translation.matrix_[1][3] = -pos_y;
    tmp_camera_translation.matrix_[2][3] = -pos_z;
    Matrix tmp_camera_rotation = Matrix();
    tmp_camera_rotation.matrix_[0][0] = camera_x.GetX();tmp_camera_rotation.matrix_[0][1] = camera_x.GetY();tmp_camera_rotation.matrix_[0][2] = camera_x.GetZ();
    tmp_camera_rotation.matrix_[1][0] = camera_y.GetX();tmp_camera_rotation.matrix_[1][1] = camera_y.GetY();tmp_camera_rotation.matrix_[1][2] = camera_y.GetZ();
    tmp_camera_rotation.matrix_[2][0] = camera_z.GetX();tmp_camera_rotation.matrix_[2][1] = camera_z.GetY();tmp_camera_rotation.matrix_[2][2] = camera_z.GetZ();
    this->matrix_ = (tmp_camera_rotation * tmp_camera_translation).matrix_;
  }
  /*Projection矩阵
  * halve = (fov/2)*m_pi/180;
  * n = zN;
  * f = zF;
  * t = tan(halve)*n;
  * b = -t;
  * r = t * aspect;
  * l = -r;
  */
  void Matrix::ProjectionMatrix(float top_face, float bottom_face, float near_face, float far_face, float right_face, float left_face)
  {
    matrix_[0][0] = 2 * near_face / (right_face - left_face);         matrix_[0][2] = -(right_face + left_face) / (right_face - left_face);
    matrix_[1][1] = 2 * near_face / (top_face - bottom_face);         matrix_[1][2] = -(top_face + bottom_face) / (top_face - bottom_face);
    matrix_[2][2] = (near_face + far_face) / (near_face - far_face);  matrix_[2][3] = 2 * near_face * far_face / (far_face - near_face);
    matrix_[3][2] = 1;                                                matrix_[3][3] = 0;
  }
  void Matrix::PerspectiveToOrthographicMatrix(float near_face, float far_face)
  {
    matrix_[0][0] = near_face;
    matrix_[1][1] = near_face;
    matrix_[2][2] = near_face - far_face;
    matrix_[2][3] = -near_face * far_face;
  }
  void Matrix::OrthographicMatrix(float top_face, float bottom_face, float near_face, float far_face, float right_face, float left_face)
  {
    matrix_[0][0] = 2 / (right_face - left_face); matrix_[0][3] = -(right_face + left_face) / (right_face - left_face);
    matrix_[1][1] = 2 / (top_face - bottom_face); matrix_[1][3] = -(top_face + bottom_face) / (top_face - bottom_face);
    matrix_[2][2] = 2 / (near_face - far_face);   matrix_[2][3] = -(near_face + far_face) / (near_face - far_face);
  }
  void Matrix::ViewportMatrix(float screen_width, float screen_height)
  {
    matrix_[0][0] = screen_width / 2;
    matrix_[1][1] = -screen_height / 2;
    matrix_[0][3] = screen_width / 2;
    matrix_[1][3] = screen_height / 2;
  }
  Matrix::~Matrix() {
  }
  int Matrix::GetMatrixOrder() const
  {
    return this->matrix_order_;
  }
  void Matrix::Identity() {
    for (int i = 0; i < matrix_order_; i++) {
      for (int j = 0; j < matrix_order_; j++) {
        if (i == j) {
          matrix_[i][j] = 1;
        }
        matrix_[i][j] = 0;
      }
    }
  }
  void Matrix::OutPutMatrix() {
    for (int i = 0; i < matrix_order_; i++) {
      for (int j = 0; j < matrix_order_; j++) {
        std::cout << matrix_[i][j] << " ";
      }
      std::cout << std::endl; 
    }
  }
  void Matrix::ModelScale(float x, float y, float z)
  {
    matrix_[0][0] = x;
    matrix_[1][1] = y;
    matrix_[2][2] = z;
  }
  void Matrix::ModelRotationX(float alpha)
  {
    matrix_[1][1] = cos(alpha * 180 / M_PI); matrix_[1][2] = -sin(alpha * 180 / M_PI);
    matrix_[2][1] = sin(alpha * 180 / M_PI); matrix_[2][2] = cos(alpha * 180 / M_PI);
  }
  void Matrix::ModelRotationY(float beta)
  {
    matrix_[0][0] = cos(beta * 180 / M_PI); matrix_[0][2] = sin(beta * 180 / M_PI);
    matrix_[2][0] = -sin(beta * 180 / M_PI); matrix_[2][2] = cos(beta * 180 / M_PI);
  }
  void Matrix::ModelRotationZ(float gamma)
  {
    matrix_[0][0] = cos(gamma * 180 / M_PI); matrix_[0][1] = -sin(gamma * 180 / M_PI);
    matrix_[1][0] = sin(gamma * 180 / M_PI); matrix_[1][1] = cos(gamma * 180 / M_PI);
  }
  void Matrix::ModelRotation(float alpha, float beta, float gamma)
  {
    ModelRotationX(alpha);
    ModelRotationY(beta);
    ModelRotationZ(gamma);
  }
  void Matrix::ModelTranslation(float x, float y, float z)
  {
    matrix_[0][3] = x;
    matrix_[1][3] = y;
    matrix_[2][3] = z;
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
  /*函数注释：需要判断符号是否相等，1算符号，2符号运算*/
  bool IsEqual(float a, float b, float c)
  {
    if (a >= 0 && b >= 0 && c >= 0) {
      return true;
    }
    else if (a <= 0 && b <= 0 && c <= 0) {
      return true;
    }
    else {
      return false;
    }
  }

  float MaxNum(float a, float b, float c)
  {
    if (a >= b) {
      if (a >= c) {
        return a;
      }
      else {
        return c;
      }
    }
    else {
      if (b >= c) {
        return b;
      }
      else {
        return c;
      }
    }
  }
  float MinNum(float a, float b, float c)
  {
    if (a <= b) {
      if (a <= c) {
        return a;
      }
      else {
        return c;
      }
    }
    else {
      if (b <= c) {
        return b;
      }
      else {
        return c;
      }
    }
  }

}
