/**
 * @file wavefront_obj_parser.cpp
 * @author 谢泽浩
 * @date 2023-12-23
 * @brief 读取obj文件并解析
 * @code UTF-8
 * @date 2023-12-23
 */
#ifndef _WAVEFRONT_OBJ_PARSER_CPP_
#define _WAVEFRONT_OBJ_PARSER_CPP_
#include"wavefront_obj_parser.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "../my_math/my_math.h"
#include "../my_models/face.h"

using namespace std;
using namespace XX_XZH;

// v 中存放所有点坐标
vector<Vector3> v;
// f 面，存放点坐标顺序
vector<Face> f;
int wavefront_obj_parser()
{
  ifstream obj_file;
  obj_file.open("../obj_model/triangle.obj");
  if (!obj_file.is_open())
  {
    cout << "文件打开失败" << endl;
    return 0;
  }
  cout << "文件打开成功" << endl;
  char buff[100] = {};
  char *p, *q;
  while (obj_file.getline(buff, sizeof(buff)))
  {
    if (buff[0] == 'v' && buff[1] == ' ')
    {
      Vector3 tmp;
      tmp.SetX(strtod(buff + 2, &p));
      tmp.SetY(strtod(p, &p));
      tmp.SetZ(strtod(p, &p));
      v.push_back(tmp);
    }
    if (buff[0] == 'f' && buff[1] == ' ')
    {
      // 单独写一个函数，解析面
      Face tmp_face;
      // 按照空格 分割字符串
      p = strtok(buff + 2, " ");
      // 继续拆分全部字符串
      while (p != NULL)
      {
        // 使用q指针，接一下分割好的字符串（1/2/3)
        q = p;
        // 第一个字符肯定是数字
        int a = strtol(q, &q, 10);
        tmp_face.vertex_index.push_back(a);
        cout << "a = " << a << endl;
        // 第二个可能是/，也可能是\0
        if (*q == '/')
        {
          // q往下走
          q++;
        }
        else if (*q == '\0')
        {
          // 结束了，拆分下一个，并且重新循环
          p = strtok(NULL, " ");
          continue;
        }
        // 第三个可能是/，也可能是数字
        if (*q == '/')
        {
          // q往下走
          q++;
        }
        else
        {
          int b = strtol(q, &q, 10);
          tmp_face.vertex_texture_index.push_back(b);
          cout << "b = " << b << endl;
        }
        // 第四个可能是/，也可能是\0，也可能是数字
        if (*q == '/')
        {
          // q往下走
          q++;
        }
        else if (*q == '\0')
        {
          // 结束了，拆分下一个，并且重新循环
          p = strtok(NULL, " ");
          continue;
        }
        else
        {
          int c = strtol(q, &q, 10);
          tmp_face.vertex_normal_index.push_back(c);
          cout << "c = " << c << endl;
        }
        // 第五个可能是\0，也可能是数字
        if (*q == '\0')
        {
          // 结束了，拆分下一个，并且重新循环
          p = strtok(NULL, " ");
          continue;
        }
        else
        {
          int d = strtol(q, &q, 10);
          tmp_face.vertex_normal_index.push_back(d);
          cout << "d = " << d << endl;
        }
        // 第六个肯定是\0
        if (*q == '\0')
        {
          // 结束了，拆分下一个，并且重新循环
          p = strtok(NULL, " ");
          continue;
        }
        p = strtok(NULL, " ");
      }
      f.push_back(tmp_face);
    }
  }
  for (int i = 0; i < v.size(); i++)
  {
    v[i].OutPutVector3();
  }
  for (int i = 0; i < f.size(); i++)
  {
    f[i].OutputFace();
  }
  return 0;
}
#endif
