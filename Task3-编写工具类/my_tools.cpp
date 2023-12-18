/*
* �ļ�����my_tools.h
* ������Ϣ��л���
* �ع�ʱ�䣺2023-12-17
* �ļ����ݣ�win API��ͼ����������Ҫ�Ĺ�����
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
    //�Ҷ����������������궼��1
    assert(start_location.GetW() == 1);
    assert(end_location.GetW() == 1);
    //����б��
    float k = (end_location.GetY() - start_location.GetY()) / (end_location.GetX() - start_location.GetX());
    //����ؾ�
    float b = start_location.GetY() - k * start_location.GetX();
    //����һ����ά�����꣬��־�ų�ʼ��
    Vector2 tmp_dot(start_location.GetX(),start_location.GetY());
    //�ж�x+1ʱ��y������
    for (int x = start_location.GetX();x < end_location.GetX(); x++)
    {
      //������yֵ����ȥ���Ƶ��yֵ���������0.5������Ƶ��yֵ��1
      (k * x + b) - (tmp_dot.GetY()) > 0.5 ? tmp_dot.SetY(tmp_dot.GetY() + 1) : tmp_dot.SetY(tmp_dot.GetY());
      tmp_dot.SetX(x);
      DrawDot(hdc,tmp_dot);
    }
  }
}
