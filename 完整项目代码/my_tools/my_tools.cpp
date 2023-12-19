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
	/*函数注释：使用DDA算法进行画线
	* 画线原理：
	* 过计算斜率，然后计算出每个x+1时，y的增量，然后判断是否大于0.5，如果大于0.5，则绘制点的y值加1
	* 如果斜率大于1，则将斜率取倒数，然后计算出每个y+1时，x的增量，然后判断是否大于0.5，如果大于0.5，则绘制点的x值加1
	*/
  void DrawLineUseDDA(HDC& hdc, Vector3& start_location, Vector3& end_location)
  {
    //我断言两个点的齐次坐标都是1
    assert(start_location.GetW() == 1);
    assert(end_location.GetW() == 1);
    //计算斜率 y = 3x - 3
    float k = (end_location.GetY() - start_location.GetY()) / (end_location.GetX() - start_location.GetX());
    //计算截距
    float b = start_location.GetY() - k * start_location.GetX();
		//如果斜率大于1，x = (1/3)y + 1
		if (k > 1) {
			k = 1 / k;
			//此时的k已经取倒数了，所以b的计算方式也要变化
			b = start_location.GetX() - k * start_location.GetY();
			//xy轴的（1，2）点 变成 yx轴的（2，1）点
			
		}
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
		for(int y = start_location.GetY();y<end_location.GetY();y++){
      //这个点的x值，减去绘制点的x值，如果大于0.5，则绘制点的x值加1
			(k * y + b) - (tmp_dot.GetX()) > 0.5 ? tmp_dot.SetX(tmp_dot.GetX() + 1) : tmp_dot.SetX(tmp_dot.GetX());
			tmp_dot.SetX(y);
			DrawDot(hdc, tmp_dot);
		}
  }
  void DrawLineUseDDALegacy(HDC& hdc, Vector3& start_location, Vector3& end_location)
  {
		//我断言两个点的齐次坐标都是1
		assert(start_location.GetW() == 1);
		assert(end_location.GetW() == 1);
		//创建两个点用来接收
		Vector3 p0 = start_location;
		Vector3 p1 = end_location;
		//计算X轴的最大差值和Y轴的最大差值
		int dx = abs(p1.GetX() - p0.GetX());
		int dy = abs(p1.GetY() - p0.GetY());
		BOOL bInterChange = FALSE;
		int e, signX, signY, temp;
		signX = (p1.GetX() > p0.GetX()) ? 1 : ((p1.GetX() < p0.GetX()) ? -1 : 0);
		signY = (p1.GetY() > p0.GetY()) ? 1 : ((p1.GetY() < p0.GetY()) ? -1 : 0);
		if (dy > dx) {
			temp = dx;
			dx = dy;
			dy = temp;
			bInterChange = TRUE;
		}
		e = -dx;
		Vector3 p = p0; // 用来接收起点
		for (int i = 0; i < dx; i++) {
			SetPixel(hdc, p.GetX(), p.GetY(), RGB(0, 0, 0));
			if (bInterChange) {
				p.SetY(p.GetY() + signY);
			}
			else {
				p.SetY(p.GetY() + signX);
			}
			e += 2 * dy;
			if (e >= 0) {
				if (bInterChange) {
					p.SetX(p.GetX() + signX);
				}
				else {
					p.SetY(p.GetY() + signY);
				}
				e -= 2 * dx;
			}
		}
		p0 = p1;
  }
}
