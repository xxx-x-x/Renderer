/*
 * 文件名：my_tools.h
 * 作者信息：谢泽浩
 * 重构时间：2023-12-17
 * 文件内容：win API绘图过程中所需要的工具类
 * 编码格式：UTF-8
 * Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
 */
#include "my_tools.h"
namespace XX_XZH
{
  void DrawDot(HDC &hdc, Vector2 &dot_location)
  {
    SetPixel(hdc, dot_location.GetX(), dot_location.GetY(), RGB(255, 0, 0));
  }
  void DrawDot(HDC &hdc, int x, int y)
  {
    SetPixel(hdc, x, y, RGB(0, 0, 0));
  }
  /*函数注释：使用DDA算法进行画线
   * 画线原理：
   * 过计算斜率，然后计算出每个x+1时，y的增量，然后判断是否大于0.5，如果大于0.5，则绘制点的y值加1
   * 如果斜率大于1，则将斜率取倒数，然后计算出每个y+1时，x的增量，然后判断是否大于0.5，如果大于0.5，则绘制点的x值加1
   */
  void DrawLineUseDDA(HDC &hdc, Vector3 start_location, Vector3 end_location)
  {
    // 我断言两个点的齐次坐标都是1
    assert(start_location.GetW() == 1);
    assert(end_location.GetW() == 1);
    // 计算斜率 y = 3x - 3
    float k = (end_location.GetY() - start_location.GetY()) / (end_location.GetX() - start_location.GetX());
    // 计算截距
    float b = start_location.GetY() - k * start_location.GetX();
    // 如果斜率大于1，x = (1/3)y + 1
    if (k > 1 || k < -1)
    {
      k = 1 / k;
      // 此时的k已经取倒数了，所以b的计算方式也要变化
      b = start_location.GetX() - k * start_location.GetY();
      // xy轴的（1，2）点 变成 yx轴的（2，1）点
      start_location.ExchangeXY();
      end_location.ExchangeXY();
    }
    // 创建一个二维点坐标，标志着初始点
    Vector2 tmp_dot(start_location.GetX(), start_location.GetY());
    // 判断x+1时，y的增量
    for (int x = start_location.GetX(); x < end_location.GetX(); x++)
    {
      // 这个点的y值，减去绘制点的y值，如果大于0.5，则绘制点的y值加1
      (k * x + b) - (tmp_dot.GetY()) > 0.5 ? tmp_dot.SetY(tmp_dot.GetY() + 1) : tmp_dot.SetY(tmp_dot.GetY());
      tmp_dot.SetX(x);
      DrawDot(hdc, tmp_dot);
    }
  }
  void DrawLineUseDDAv1(HDC &hdc, Vector3 start_location, Vector3 end_location)
  {
    // 求水平垂直距离
    int dx = start_location.GetX() - end_location.GetX();
    int dy = start_location.GetY() - end_location.GetY();
    if (dy == 0)
    {
      // 从小的开始画
      int start_x = start_location.GetX() < end_location.GetX() ? start_location.GetX() : end_location.GetX();
      // 画到大的结束
      int end_x = start_location.GetX() < end_location.GetX() ? end_location.GetX() : start_location.GetX();
      // 水平线
      for (int x = start_x; x < end_x; x++)
      {
        DrawDot(hdc, x, start_location.GetY());
      }
      return void();
    }
    if (dx == 0)
    {
      // 从小的开始画
      int start_y = start_location.GetY() < end_location.GetY() ? start_location.GetY() : end_location.GetY();
      // 画到大的结束
      int end_y = start_location.GetY() < end_location.GetY() ? end_location.GetY() : start_location.GetY();
      // 垂直线
      for (int y = start_y; y < end_y; y++)
      {
        DrawDot(hdc, start_location.GetX(), y);
      }
      return void();
    }
    // 求斜率
    float k = float(dy) / dx;
    // 定义起始点
    if (k >= -1 && k <= 1)
    {
      // 从小点开始往大点画
      if (start_location.GetX() > end_location.GetX())
      {
        // 交换起始点
        Vector3 tmp = start_location;
        start_location = end_location;
        end_location = tmp;
      }
      int x;
      float y = start_location.GetY();
      // 循环
      for (x = start_location.GetX(); x < end_location.GetX(); x++)
      {
        // 绘制点
        DrawDot(hdc, x, ROUND(y));
        // 计算y值
        y += k;
      }
    }
    else if (k > 1 && dx != 0)
    {
      // 从小点开始往大点画
      if (start_location.GetY() > end_location.GetY())
      {
        // 交换起始点
        Vector3 tmp = start_location;
        start_location = end_location;
        end_location = tmp;
      }
      int y;
      float x = start_location.GetX();
      // 循环
      for (y = start_location.GetY(); y < end_location.GetY(); y++)
      {
        // 绘制点
        DrawDot(hdc, ROUND(x), y);
        // 计算y值
        x += 1 / k;
      }
    }
    else if (k < -1 && dx != 0)
    {
      int y;
      float x = start_location.GetX();
      // 循环
      for (y = start_location.GetY(); y > end_location.GetY(); y--)
      {
        // 绘制点
        DrawDot(hdc, ROUND(x), y);
        // 计算y值
        x -= 1 / k;
      }
    }
  }
  void DrawLineUseDDALegacy(HDC &hdc, Vector3 start_location, Vector3 end_location)
  {
    // 我断言两个点的齐次坐标都是1
    assert(start_location.GetW() == 1);
    assert(end_location.GetW() == 1);
    // 创建两个点用来接收
    Vector3 p0 = start_location;
    Vector3 p1 = end_location;
    // 计算X轴的最大差值和Y轴的最大差值
    int dx = abs(p1.GetX() - p0.GetX());
    int dy = abs(p1.GetY() - p0.GetY());
    BOOL bInterChange = FALSE;
    int e, signX, signY, temp;
    signX = (p1.GetX() > p0.GetX()) ? 1 : ((p1.GetX() < p0.GetX()) ? -1 : 0);
    signY = (p1.GetY() > p0.GetY()) ? 1 : ((p1.GetY() < p0.GetY()) ? -1 : 0);
    if (dy > dx)
    {
      temp = dx;
      dx = dy;
      dy = temp;
      bInterChange = TRUE;
    }
    e = -dx;
    Vector3 p = p0; // 用来接收起点
    for (int i = 0; i < dx; i++)
    {
      SetPixel(hdc, p.GetX(), p.GetY(), RGB(0, 0, 0));
      if (bInterChange)
      {
        p.SetY(p.GetY() + signY);
      }
      else
      {
        p.SetY(p.GetY() + signX);
      }
      e += 2 * dy;
      if (e >= 0)
      {
        if (bInterChange)
        {
          p.SetX(p.GetX() + signX);
        }
        else
        {
          p.SetY(p.GetY() + signY);
        }
        e -= 2 * dx;
      }
    }
    p0 = p1;
  }
  void DrawFaceUseAABB(HDC& hdc,Face tmp_f1,std::vector<Vector3> tmp_v){
    // 调用数学库中的计算最大最小值函数
    float max_x = MAX_NUM(tmp_v[tmp_f1.vertex_index[0]].GetX(), tmp_v[tmp_f1.vertex_index[1]].GetX(), tmp_v[tmp_f1.vertex_index[2]].GetX());
    float max_y = MAX_NUM(tmp_v[tmp_f1.vertex_index[0]].GetY(), tmp_v[tmp_f1.vertex_index[1]].GetY(), tmp_v[tmp_f1.vertex_index[2]].GetY());
    float min_x = MIN_NUM(tmp_v[tmp_f1.vertex_index[0]].GetX(), tmp_v[tmp_f1.vertex_index[1]].GetX(), tmp_v[tmp_f1.vertex_index[2]].GetX());
    float min_y = MIN_NUM(tmp_v[tmp_f1.vertex_index[0]].GetY(), tmp_v[tmp_f1.vertex_index[1]].GetY(), tmp_v[tmp_f1.vertex_index[2]].GetY());
    // 光栅化，左下开始，右上结束
    for (int i = (int)min_y; i < (int)max_y; i++)
    {
      for (int j = (int)min_x; j < (int)max_x; j++)
      {
        if(DotInside(tmp_f1,tmp_v,j,i)){
          DrawDot(hdc,j,i);
        }
      }
    }
  }
}
