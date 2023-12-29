/*
* 文件名：my_math.h
* 作者信息：谢泽浩
* 重构时间：2023-12-16
* 文件内容：计算机图形学使用的数学库
* 编码格式：UTF-8
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#ifndef _MY_MATH_H_
#define _MY_MATH_H_

#define IS_EQUAL(num1,num2,num3) IsEqual(num1,num2,num3)
#define MAX_NUM(num1,num2,num3) MaxNum(num1,num2,num3)
#define MIN_NUM(num1,num2,num3) MinNum(num1,num2,num3)
#define ROUND(num) (int)(num+0.5)

#include<math.h>
#include<assert.h>
#include<iostream>
#include<string.h>
namespace XX_XZH {
  /*提前声明*/
  class Vector2;
  /*类注释：该类为三维向量类*/
  class Vector3 {
  public:
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(float x, float y, float z,float w);
    Vector3(const Vector3& tmp_v3);
    virtual ~Vector3();
    float GetX() const;
    void SetX(float x);
    float GetY() const;
    void SetY(float y);
    float GetZ() const;
    void SetZ(float z);
    float GetW() const;
    void SetW(float w);

    void Normalize(); //单位化向量
    float Norm();     //向量的模
    Vector3& Identity();
    void OutPutVector3();
    void ExchangeXY();

    Vector3& operator= (const Vector3& tmp_v3);
    float& operator[](int index);
    operator Vector2();
    Vector3 operator-();
  private:
    float x_;
    float y_;
    float z_;
    float w_;
  };
  /*类注释：该类为二维向量类*/
  class Vector2 {
  public:
    Vector2();
    Vector2(float x, float y);
    Vector2(const Vector2& tmp_v2);
    virtual ~Vector2();

    float GetX() const;
    void SetX(float x);
    float GetY() const;
    void SetY(float y);
    float GetW() const;
    void SetW(float w);

    void Normalize(); //单位化向量
    float Norm();     //向量的模
    void OutPutVector2();
    Vector2 ExchangeXY();

    Vector2 operator= (const Vector2& tmp_v2);
    operator Vector3();
  private:
    float x_;
    float y_;
    float w_;
  };
  /*类注释：自定义大小的矩阵类
  * 输入：矩阵的阶数
  * 初始值：四阶，全零；
  */
  class Matrix {
  public:
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
    friend Vector3& operator*(const Matrix& m1, Vector3& v3);
    Matrix();
    Matrix(float n11, float n12, float n13, float n14, float n21, float n22, float n23, float n24, float n31, float n32, float n33, float n34, float n41, float n42, float n43, float n44);
    Matrix(const Matrix& tmp_matrix);
    virtual ~Matrix();
    int GetMatrixOrder() const;

    /*单位矩阵，应当按照当前矩阵的阶数进行单位赋值*/
    void Identity();
    void OutPutMatrix();

    /*函数注释：Model函数*/
    void ModelScale(float x, float y, float z);
    void ModelRotationX(float alpha);
    void ModelRotationY(float beta);
    void ModelRotationZ(float gamma);
    void ModelRotation(float alpha, float beta, float gamma);
    void ModelTranslation(float x, float y, float z);
    /*函数注释：View函数*/
    void ViewMatrix(float pos_x, float pos_y, float pos_z, float target_x, float target_y, float target_z, float up_x, float up_y, float up_z);
    /*函数注释：Projection函数
    * ProjectionMatrix = [OrthographicMatrix][PerspectiveToOrthographicMatrix]
    * PerspectiveToOrthographicMatrix 和 OrthographicMatrix矩阵不会被调用
    */
    void ProjectionMatrix(float top_face, float bottom_face, float near_face, float far_face, float right_face, float left_face);
    void PerspectiveToOrthographicMatrix(float near_face, float far_face);
    void OrthographicMatrix(float top_face, float bottom_face, float near_face, float far_face, float right_face, float left_face);
    /*函数注释：Viewport函数*/
    void ViewportMatrix(float screen_width, float screen_height);
  private:
    float matrix_[4][4];
    int matrix_order_;
  };
  /*三维向量的运算*/
  float Dot(const Vector3& left_v3, const Vector3& right_v3);     //点乘
  Vector3 Cross(const Vector3& left_v3, const Vector3& right_v3); //叉乘
  Vector3 Lerp(const Vector3& from, const Vector3& to, float t);  //插值
  Vector3 operator+(const Vector3& left_v3, const Vector3& right_v3);//加
  Vector3 operator-(const Vector3& left_v3, const Vector3& right_v3);//减
  float operator*(const Vector3& tmp_v1, const Vector3& tmp_v2);  //点乘
  Vector3 Cross(const Vector3& left_v3, const Vector3& right_v3); //叉乘
  Vector3 operator*(const Vector3& left_v3, float right);//数乘
  Vector3 operator*(float left, const Vector3& right_v3);//数乘
  Vector3 operator/(const Vector3& left_v3, float right);//除
  bool operator==(const Vector3& left_v3, const Vector3& right_v3);//关系
  bool operator!=(const Vector3& left_v3, const Vector3& right_v3);//关系

  /*二维向量的运算*/
  float Dot(const Vector2& left_v2, const Vector2& right_v2);     //点乘
  float Cross(const Vector2& left_v2, const Vector2& right_v2); //叉乘
  Vector2 Lerp(const Vector2& from, const Vector2& to, float t);  //插值
  Vector2 operator+(const Vector2& left_v2, const Vector2& right_v2);//加
  Vector2 operator-(const Vector2& left_v2, const Vector2& right_v2);//减
  float operator*(const Vector2& tmp_v1, const Vector2& tmp_v2);  //点乘
  Vector2 operator*(const Vector2& left_v2, float right);//数乘
  Vector2 operator*(float left, const Vector2& right_v2);//数乘
  Vector2 operator/(const Vector2& left_v2, float right);//除
  bool operator==(const Vector2& left_v2, const Vector2& right_v2);//关系
  bool operator!=(const Vector2& left_v2, const Vector2& right_v2);//关系

  /*矩阵的运算*/
  Matrix operator*(const Matrix& m1, const Matrix& m2);
  Vector3& operator*(const Matrix& m1, Vector3& v3);
  /*其他数学函数*/
  bool IsEqual(float a, float b, float c);
  float MaxNum(float a, float b, float c);
  float MinNum(float a, float b, float c);
  Vector3 Barycentric(Vector3& a,Vector3& b,Vector3& c,Vector3& p);
}
#endif // !_MY_MATH_H_
