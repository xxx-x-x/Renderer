/*
* 文件名：my_tools.h
* 作者信息：谢泽浩
* 重构时间：2023-12-17
* 文件内容：win API绘图过程中所需要的工具类
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#ifndef _MY_TOOLS_H_
#define _MY_TOOLS_H_
#include<assert.h>
#include<Windows.h>
#include"../my_math/my_math.h"
namespace XX_XZH {
  /*函数注释：根据二维点向量画图*/
  void DrawDot(HDC& hdc, Vector2& dot_location);
  /*函数注释：使用DDA算法进行画线
  * 参数说明：输入屏幕HDC，起始点坐标，终止点坐标；
  */
  void DrawLineUseDDA(HDC& hdc,Vector3& start_location,Vector3& end_location);/*使用DDA算法画线*/
  void DrawLineUseDDALegacy(HDC& hdc, Vector3& start_location, Vector3& end_location);/*使用DDA算法画线*/
}
#endif // !_MY_TOOLS_

