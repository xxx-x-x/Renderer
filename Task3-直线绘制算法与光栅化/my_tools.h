/*
* �ļ�����my_tools.h
* ������Ϣ��л���
* �ع�ʱ�䣺2023-12-17
* �ļ����ݣ�win API��ͼ����������Ҫ�Ĺ�����
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#ifndef _MY_TOOLS_H_
#define _MY_TOOLS_H_
#include<assert.h>
#include<Windows.h>
#include"../my_math/my_math.h"
#include"../my_models/my_triangle.h"
namespace XX_XZH {
  /*����ע�ͣ����ݶ�ά��������ͼ*/
  void DrawDot(HDC& hdc, Vector2& dot_location);
  void DrawDot(HDC& hdc, int x, int y);
  /*����ע�ͣ�ʹ��DDA�㷨���л���
  * ����˵����������ĻHDC����ʼ�����꣬��ֹ�����ꣻ
  */
  void DrawLineUseDDA(HDC& hdc,Vector3 start_location,Vector3 end_location);/*ʹ��DDA�㷨����*/
  /*����ע�ͣ���legacy��ʹ��DDA�㷨���л���
  * ����˵����������ĻHDC����ʼ�����꣬��ֹ�����ꣻ
  * ������飺��ʱûдע�͡����ڿ������ˣ����ǿ�����������
  */
  void DrawLineUseDDAv1(HDC& hdc, Vector3 start_location, Vector3 end_location);/*ʹ��DDA�㷨����*/
  void DrawLineUseDDALegacy(HDC& hdc, Vector3 start_location, Vector3 end_location);/*ʹ��DDA�㷨����*/
  /*����ע�ͣ���������Ƭ������ɫ
  * ����˵���������ĻHDC��������Ƭ��������������
  */
  void DrawTriangleUseAABB(HDC& hdc,Triangle& triangle);
}
#endif // !_MY_TOOLS_

