/*
* (legacy) 注意，该文件已经弃用
* 文件名：my_triangle.h
* 作者信息：谢泽浩
* 重构时间：2023-12-18
* 文件内容：模型最基础的三角面片
* 编码格式：UTF-8
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#ifndef _MY_TRIANGLE_H_
#define _MY_TRIANGLE_H_
#include<vector>
#include"../my_math/my_math.h"

namespace XX_XZH {
  /*类注释：Triangle是三角形类
  * 该类由三个点构成，所以应该有三个点坐标
  * 该类应该提供一个判断像素点是否在三角形内的函数
  * 叉乘之后判断，右移31位，如果为0，则在三角形内
  */
  class Triangle {
  public:
    Triangle();
    Triangle(Vector2 dots_a, Vector2 dots_b, Vector2 dots_c);
    virtual ~Triangle();
    friend const int DotInside(Triangle& tmp_tri, float dot_x,float dot_y);

    const Vector2* GetTriangleDots() const;
    void OutputTriangle()const;
  private:
    Vector2* triangle_dots;
  };
  /*全局函数注释：判断点，是否在三角形内
  * 定义思路：
  * 这个点与三角形三个顶点构成向量与三条边向量叉乘
  */
  const int DotInside(Triangle& tmp_tri,const float dot_x,const float dot_y);
}
#endif // !_MY_TRIANGLE_H_
