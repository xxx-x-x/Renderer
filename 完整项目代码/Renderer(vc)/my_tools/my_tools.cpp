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
  void DrawDot(HDC &hdc, int &x, int &y)
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
        SetPixel(hdc, x, start_location.GetY(), RGB(0, 0, 0));
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
        SetPixel(hdc, start_location.GetX(), y, RGB(0, 0, 0));
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
        SetPixel(hdc, x, ROUND(y), RGB(0, 0, 0));
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
        SetPixel(hdc, ROUND(x), y, RGB(0, 0, 0));
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
        SetPixel(hdc, ROUND(x), y, RGB(0, 0, 0));
        // 计算y值
        x -= 1 / k;
      }
    }
  }
  void DrawLineUseBresenham(HDC& hdc,Vector3 start_location,Vector3 end_location)/*使用Bresenham算法画线*/
  {
    // 我断言两个点的齐次坐标都是1
    assert(start_location.GetW() == 1);
    assert(end_location.GetW() == 1);
    int x0 =  start_location.GetX();
    int y0 = start_location.GetY();
    int x1 = end_location.GetX();
    int y1 = end_location.GetY();
    bool steep = false; 
    if (std::abs(x0-x1)<std::abs(y0-y1)) { 
        std::swap(x0, y0); 
        std::swap(x1, y1); 
        steep = true; 
    } 
    if (x0>x1) { 
        std::swap(x0, x1); 
        std::swap(y0, y1); 
    } 
    int dx = x1-x0; 
    int dy = y1-y0; 
    float derror = std::abs(dy/float(dx)); 
    float error = 0; 
    int y = y0; 
    for (int x=x0; x<=x1; x++) { 
        if (steep) { 
          SetPixel(hdc,y,x,RGB(0,0,0));
        } else { 
          SetPixel(hdc,x,y,RGB(0,0,0));
        } 
        error += derror; 
        if (error>.5) { 
            y += (y1>y0?1:-1); 
            error -= 1.; 
        } 
    } 
  }
  void DrawFaceUseBarycentricAABB(HDC& hdc,float *zbuffer,int face_index,WaveFrontOBJ& obj,double intensity){
    Vector3 v1,v2,v3;
    v1 = obj.v[obj.f[face_index].vertex_index[0]-1];
    v2 = obj.v[obj.f[face_index].vertex_index[1]-1];
    v3 = obj.v[obj.f[face_index].vertex_index[2]-1];
    Vector3 vt1,vt2,vt3;
    vt1 = obj.vt[obj.f[face_index].vertex_texture_index[0]-1];
    vt2 = obj.vt[obj.f[face_index].vertex_texture_index[1]-1];
    vt3 = obj.vt[obj.f[face_index].vertex_texture_index[2]-1];
    // 调用数学库中的计算最大最小值函数
    float max_x = MAX_NUM(v1.GetX(), v2.GetX(), v3.GetX());
    float min_x = MIN_NUM(v1.GetX(), v2.GetX(), v3.GetX());
    float max_y = MAX_NUM(v1.GetY(), v2.GetY(), v3.GetY());
    float min_y = MIN_NUM(v1.GetY(), v2.GetY(), v3.GetY());
    // 光栅化，原点在左上角，所以左上角开始，右下角结束，
    Vector3 p;
    Vector3 p_vt;
    for (int i = (int)min_y+1; i < (int)max_y+1; i++)
    {
      for (int j = (int)min_x+1; j < (int)max_x+1; j++)
      {
        Vector3 p = Vector3(j,i,0);
        //判断重心坐标有无负值
        Vector3 barycentric = Barycentric(v1,v2,v3,p);
        if(barycentric.GetX() < 0 || barycentric.GetY()<0 || barycentric.GetZ() <0){
          continue;
        }
        //一个像素点的z = 其他三个像素点的z 乘以 重心坐标
        p.SetZ(v1.GetZ()*barycentric.GetX() + v2.GetZ()*barycentric.GetY() + v3.GetZ()*barycentric.GetZ());
        //p_vt(u,v,0);
        p_vt.SetX(vt1.GetX()*barycentric.GetX()+vt2.GetX()*barycentric.GetY()+vt3.GetX()*barycentric.GetZ());
        p_vt.SetY(vt1.GetY()*barycentric.GetX()+vt2.GetY()*barycentric.GetY()+vt3.GetY()*barycentric.GetZ());
        //贴图
        if(zbuffer[int(j+i*800)]<=p.GetZ()){
          zbuffer[int(j+i*800)]=p.GetZ();
          TGAColor rgb =  obj.texture_tga.get(p_vt.GetX(),p_vt.GetY());
          SetPixel(hdc,j,i,RGB(rgb.bgra[2]*intensity,rgb.bgra[1]*intensity,rgb.bgra[0]*intensity));
          //SetPixel(hdc,j,i,RGB(255*intensity,255*intensity,255*intensity));
        }
      }
    }
  }

  void DrawFaceUseBarycentricAABB(HDC& hdc,float *zbuffer,Vector3 v1,Vector3 v2,Vector3 v3,COLORREF rgb)
  {
    // 调用数学库中的计算最大最小值函数
    float max_x = MAX_NUM(v1.GetX(), v2.GetX(), v3.GetX());
    float min_x = MIN_NUM(v1.GetX(), v2.GetX(), v3.GetX());
    float max_y = MAX_NUM(v1.GetY(), v2.GetY(), v3.GetY());
    float min_y = MIN_NUM(v1.GetY(), v2.GetY(), v3.GetY());
    // 光栅化，原点在左上角，所以左上角开始，右下角结束，
    Vector3 p;
    for (int i = (int)min_y; i < (int)max_y; i++)
    {
      for (int j = (int)min_x; j < (int)max_x; j++)
      {
        Vector3 p = Vector3(j,i,0);
        //判断重心坐标有无负值
        Vector3 barycentric = Barycentric(v1,v2,v3,p);
        if(barycentric.GetX() < 0 || barycentric.GetY()<0 || barycentric.GetZ() <0){
          continue;
        }
        //一个像素点的z = 其他三个像素点的z 乘以 重心坐标
        p.SetZ(v1.GetZ()*barycentric.GetX() + v2.GetZ()*barycentric.GetY() + v3.GetZ()*barycentric.GetZ());
        if(zbuffer[int(j+i*800)]<=p.GetZ()){
          zbuffer[int(j+i*800)]=p.GetZ();
          SetPixel(hdc,j,i,rgb);
        }
      }
    }
  }
  /**
   * 函数注释：该函数用来画面，参考自tinyrender算法
   * 函数输入：三个点坐标，加一个面坐标
   */
  void DrawFaceUseLine(HDC &hdc, Vector3 v0, Vector3 v1, Vector3 v2, COLORREF rgb)
  {
    // 不知道三个点的情况，手动让他们从低到高排序
    if (v0.GetY() > v1.GetY())
      std::swap(v0, v1);
    if (v0.GetY() > v2.GetY())
      std::swap(v0, v2);
    if (v1.GetY() > v2.GetY())
      std::swap(v1, v2);
    //第一步，画线框，其实可以不用画
    DrawLineUseBresenham(hdc,v0,v1);
    DrawLineUseBresenham(hdc,v1,v2);
    DrawLineUseBresenham(hdc,v2,v0);
    //第二步，计算y轴的最大差值
    int total_height = v2.GetY() - v0.GetY();
    //第三步，先下半部分，从左下角开始
    for(int y=v0.GetY();y<=v1.GetY();y++){
      int segment_height = v1.GetY() - v0.GetY() + 1;
      //v0和v2之间的斜率
      float v0_v2_k = (float)(y-v0.GetY())/total_height;
      //v0和v1之间的斜率 
      float v0_v1_k = (float)(y-v0.GetY())/segment_height;
      //利用相似三角形原理
      Vector3 A = v0 + (v2 - v0) * v0_v2_k;
      Vector3 B = v0 + (v1 - v0) * v0_v1_k;
      //方法一，找到两个点，直接画线
      //DrawLineUseBresenham(hdc,A,B);
      //方法二，找到两个点，循环画点
      if(A.GetX()>B.GetX()) std::swap(A,B);
      for(int j = A.GetX();j<=B.GetX();j++){
        SetPixel(hdc,j,y,rgb);
      }
    }
    for(int y =v1.GetY();y<=v2.GetY();y++){
      int segment_height = v2.GetY()-v1.GetY();
      //计算v0和v2之间的斜率
      float v0_v2_k = (float)(y-v0.GetY())/total_height;
      //计算v1和v2之间的斜率
      float v1_v2_k = (float)(y-v1.GetY())/segment_height;
      //利用相似三角形原理
      Vector3 A = v0 + (v2 - v0)*v0_v2_k;
      Vector3 B = v1 + (v2 - v1)*v1_v2_k;
      if(A.GetX()>B.GetX()) std::swap(A,B);
      for(int j=A.GetX();j<=B.GetX();j++){
        SetPixel(hdc,j,y,rgb);
      }
    }
  }
}
