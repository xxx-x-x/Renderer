/*
* �ļ�����my_triangle.h
* ������Ϣ��л���
* �ع�ʱ�䣺2023-12-18
* �ļ����ݣ�ģ���������������Ƭ
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#ifndef _MY_TRIANGLE_H_
#define _MY_TRIANGLE_H_
#include"../my_math/my_math.h"
namespace XX_XZH {
  enum IS_INSIDE {OUTSIDE=0,INSIDE,ONLINE};
  /*��ע�ͣ�Triangle����������
  * �����������㹹�ɣ�����Ӧ��������������
  * ����Ӧ���ṩһ���ж����ص��Ƿ����������ڵĺ���
  * ���֮���жϣ�����31λ�����Ϊ0��������������
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
  /*ȫ�ֺ���ע�ͣ��жϵ㣬�Ƿ�����������
  * ����˼·��
  * ��������������������㹹���������������������
  * �������31λֻ�������ţ����������������Ϊ0��������������
  */
  const int DotInside(Triangle& tmp_tri,const float dot_x,const float dot_y);
}
#endif // !_MY_TRIANGLE_H_
