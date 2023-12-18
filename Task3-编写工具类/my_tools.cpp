/*
* 文件名：my_tools.h
* 作者信息：谢泽浩
* 重构时间：2023-12-17
* 文件内容：win API绘图过程中所需要的工具类
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#include"my_tools.h"
namespace XX_XZH {
  void DrawDot(HDC& hdc, Vector2& dot_location)
  {
    SetPixel(hdc, dot_location.GetX(), dot_location.GetY(), RGB(255, 0, 0));
  }
  void DrawLineUseDDA(HDC& hdc, Vector3& start_location, Vector3& end_location)
  {
    //我断言两个点的齐次坐标都是1
    assert(start_location.GetW() == 1);
    assert(end_location.GetW() == 1);
    //计算斜率
    float k = (end_location.GetY() - start_location.GetY()) / (end_location.GetX() - start_location.GetX());
    //计算截距
    float b = start_location.GetY() - k * start_location.GetX();
    //创建一个二维点坐标，标志着初始点
    Vector2 tmp_dot(start_location.GetX(),start_location.GetY());
    //判断x+1时，y的增量
    for (int x = start_location.GetX();x < end_location.GetX(); x++)
    {
      //这个点的y值，减去绘制点的y值，如果大于0.5，则绘制点的y值加1
      (k * x + b) - (tmp_dot.GetY()) > 0.5 ? tmp_dot.SetY(tmp_dot.GetY() + 1) : tmp_dot.SetY(tmp_dot.GetY());
      tmp_dot.SetX(x);
      DrawDot(hdc,tmp_dot);
    }
  }
}
