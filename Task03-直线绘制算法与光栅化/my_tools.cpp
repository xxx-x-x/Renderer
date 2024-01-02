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
	void DrawDot(HDC& hdc, int x, int y)
	{
		SetPixel(hdc, x, y, RGB(255, 0, 0));
	}
	/*����ע�ͣ�ʹ��DDA�㷨���л���
	* ����ԭ��
	* ������б�ʣ�Ȼ������ÿ��x+1ʱ��y��������Ȼ���ж��Ƿ����0.5���������0.5������Ƶ��yֵ��1
	* ���б�ʴ���1����б��ȡ������Ȼ������ÿ��y+1ʱ��x��������Ȼ���ж��Ƿ����0.5���������0.5������Ƶ��xֵ��1
	*/
  void DrawLineUseDDA(HDC& hdc, Vector3 start_location, Vector3 end_location)
  {
    //�Ҷ����������������궼��1
    assert(start_location.GetW() == 1);
    assert(end_location.GetW() == 1);
    //����б�� y = 3x - 3
    float k = (end_location.GetY() - start_location.GetY()) / (end_location.GetX() - start_location.GetX());
    //����ؾ�
    float b = start_location.GetY() - k * start_location.GetX();
		//���б�ʴ���1��x = (1/3)y + 1
		if (k > 1 || k < -1) {
			k = 1 / k;
			//��ʱ��k�Ѿ�ȡ�����ˣ�����b�ļ��㷽ʽҲҪ�仯
			b = start_location.GetX() - k * start_location.GetY();
			//xy��ģ�1��2���� ��� yx��ģ�2��1����
			start_location.ExchangeXY(); end_location.ExchangeXY();
		}
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
	void DrawLineUseDDAv1(HDC& hdc, Vector3 start_location, Vector3 end_location)
	{
		//��ˮƽ��ֱ����
		int dx = start_location.GetX() - end_location.GetX();
		int dy = start_location.GetY() - end_location.GetY();
		if (dy == 0) {
			//��С�Ŀ�ʼ��
			int start_x = start_location.GetX() < end_location.GetX() ? start_location.GetX() : end_location.GetX();
			//������Ľ���
			int end_x = start_location.GetX() < end_location.GetX() ? end_location.GetX() : start_location.GetX();
      //ˮƽ��
			for (int x = start_x; x < end_x; x++) {
        DrawDot(hdc, x, start_location.GetY());
      }
			return void();
		}
		if (dx == 0) {
			//��С�Ŀ�ʼ��
			int start_y = start_location.GetY() < end_location.GetY() ? start_location.GetY() : end_location.GetY();
			//������Ľ���
			int end_y = start_location.GetY() < end_location.GetY() ? end_location.GetY() : start_location.GetY();
      //��ֱ��
			for (int y = start_y; y < end_y; y++) {
        DrawDot(hdc, start_location.GetX(), y);
      }
			return void();
		}
		//��б��
		float k = float(dy) / dx;
			//������ʼ��
		if (k >= -1 && k <= 1) {
			//��С�㿪ʼ����㻭
			if (start_location.GetX() > end_location.GetX()) {
        //������ʼ��
        Vector3 tmp = start_location;
        start_location = end_location;
        end_location = tmp;
			}
      int x;
      float y = start_location.GetY();
      //ѭ��
      for (x = start_location.GetX(); x < end_location.GetX(); x++) {
        //���Ƶ�
        DrawDot(hdc, x, ROUND(y));
        //����yֵ
        y += k;
      }
		}
		else if (k > 1 && dx != 0) {
			//��С�㿪ʼ����㻭
			if (start_location.GetY() > end_location.GetY()) {
        //������ʼ��
        Vector3 tmp = start_location;
        start_location = end_location;
        end_location = tmp;
			}
			int y;
			float x = start_location.GetX();
			//ѭ��
			for (y = start_location.GetY(); y < end_location.GetY(); y++) {
				//���Ƶ�
				DrawDot(hdc, ROUND(x), y);
				//����yֵ
				x += 1 / k;
			}
		}else if(k<-1 && dx != 0) {
      int y;
      float x = start_location.GetX();
      //ѭ��
      for (y = start_location.GetY(); y > end_location.GetY(); y--) {
        //���Ƶ�
        DrawDot(hdc, ROUND(x), y);
        //����yֵ
        x -= 1 / k;
      }
    }
	}
  void DrawLineUseDDALegacy(HDC& hdc, Vector3 start_location, Vector3 end_location)
  {
		//�Ҷ����������������궼��1
		assert(start_location.GetW() == 1);
		assert(end_location.GetW() == 1);
		//������������������
		Vector3 p0 = start_location;
		Vector3 p1 = end_location;
		//����X�������ֵ��Y�������ֵ
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
		Vector3 p = p0; // �����������
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
	void DrawTriangleUseAABB(HDC& hdc, Triangle& triangle) {
		//������ѧ���еļ��������Сֵ����
		float max_x = MAX_NUM(triangle.GetTriangleDots()[0].GetX(), triangle.GetTriangleDots()[1].GetX(), triangle.GetTriangleDots()[2].GetX());
		float max_y = MAX_NUM(triangle.GetTriangleDots()[0].GetY(), triangle.GetTriangleDots()[1].GetY(), triangle.GetTriangleDots()[2].GetY());
		float min_x = MIN_NUM(triangle.GetTriangleDots()[0].GetX(), triangle.GetTriangleDots()[1].GetX(), triangle.GetTriangleDots()[2].GetX());
		float min_y = MIN_NUM(triangle.GetTriangleDots()[0].GetY(), triangle.GetTriangleDots()[1].GetY(), triangle.GetTriangleDots()[2].GetY());
		//��դ�������¿�ʼ�����Ͻ���
		for (int i = (int)min_y; i < (int)max_y; i++) {
			for (int j = (int)min_x; j < (int)max_x; j++) {
				if (DotInside(triangle, j, i)) {
					DrawDot(hdc, j, i);
				}
			}
		}
	}
}
