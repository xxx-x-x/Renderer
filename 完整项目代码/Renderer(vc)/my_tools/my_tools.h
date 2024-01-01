/*
* 文件名：my_tools.h
* 作者信息：谢泽浩
* 重构时间：2023-12-17
* 文件内容：win API绘图过程中所需要的工具类
* 编码格式：UTF-8
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#ifndef _MY_TOOLS_H_
#define _MY_TOOLS_H_
#include<assert.h>
#include<Windows.h>
#include"../my_math/my_math.h"
#include"../my_models/face.h"
#include"../my_models/wavefront_obj.h"
namespace XX_XZH {
  /*函数注释：根据二维点向量画图*/
  void DrawDot(HDC& hdc, Vector2& dot_location);
  void DrawDot(HDC& hdc, int& x, int& y);
  /*函数注释：（legacy）使用DDA算法进行画线
  * 参数说明：输入屏幕HDC，起始点坐标，终止点坐标；
  * 函数简介：当时没写注释。现在看不懂了，但是可以正常运行
  */
  void DrawLineUseDDA(HDC& hdc, Vector3 start_location, Vector3 end_location);/*使用DDA算法画线*/
  /*函数注释：对三角面片进行着色
  * 参数说明：输入屏幕HDC，三角面片的三个顶点坐标,以及一个面
  */
  void DrawLineUseBresenham(HDC& hdc,Vector3 start_location,Vector3 end_location);/*使用Bresenham算法画线*/
  /**
   * 函数注释：使用AABB包围盒，包围面后，对面进行扫描
   * 传入参数：三个顶点坐标
  */
  void DrawFaceUseBarycentricAABB(HDC& hdc,float *zbuffer,Vector3 v1,Vector3 v2,Vector3 v3,COLORREF rgb);
  /**
   * 函数注释：使用AABB包围盒，包围面后，对面进行扫描
   * 传入参数：面索引，模型
  */
  void DrawFaceUseBarycentricAABB(HDC& hdc,float *zbuffer,int face_index,WaveFrontOBJ& obj,double intensity);
  /**
   * 函数注释：利用向量相似三角形原理，得到三角形同一Y的左右两个点，遍历着色之间的所有点
  */
  void DrawFaceUseLine(HDC& hdc,Vector3 v1,Vector3 v2,Vector3 v3,COLORREF rgb);
}
#endif // !_MY_TOOLS_

