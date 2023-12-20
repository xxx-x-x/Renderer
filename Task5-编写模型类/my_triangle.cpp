/*
* 文件名：my_triangle.cpp
* 作者信息：谢泽浩
* 重构时间：2023-12-18
* 文件内容：模型最基础的三角面片
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#include "my_triangle.h"
namespace XX_XZH {
  Triangle::Triangle()
  {
    triangle_dots = new Vector2[3];
  }
  Triangle::Triangle(Vector2 dots_a, Vector2 dots_b, Vector2 dots_c)
  {
    triangle_dots = new Vector2[3];
    triangle_dots[0] = dots_a;
    triangle_dots[1] = dots_b;
    triangle_dots[2] = dots_c;
  }
  Triangle::~Triangle()
  {
    std::cout << "~Triangle" << std::endl;
    delete []triangle_dots;
  }
  //关键词限定成员变量不被修改，但是不能防止指针指向的内容被修改
  const Vector2* Triangle::GetTriangleDots() const
  {
    return triangle_dots;
  }
  void Triangle::OutputTriangle() const
  {
    std::cout << "Triangle dots:" << std::endl;
    for (int i = 0; i < 3; i++) {
      std::cout << triangle_dots[i].GetX() << " " << triangle_dots[i].GetY() << std::endl;
    }
  }
  const int DotInside(Triangle& tmp_tri,const float dot_x,const float dot_y)
  {
    std::vector<float> tmp_result;
    Vector2 dot_p(dot_x,dot_y);
    for (int i = 0; i < 3; i++) {
      Vector2 vertex_sub_vertex = tmp_tri.triangle_dots[(i + 1) % 3] - tmp_tri.triangle_dots[i];
      Vector2 dot_p_sub_vertex = dot_p - tmp_tri.triangle_dots[i];
      tmp_result.push_back(Cross(vertex_sub_vertex, dot_p_sub_vertex));
    }
    return IS_EQUAL(tmp_result[0], tmp_result[1], tmp_result[2]) == true ? INSIDE:OUTSIDE;
  }
}
