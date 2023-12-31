/**
 * @file wavefront_obj_parser.cpp
 * @author 谢泽浩
 * @date 2023-12-23
 * @brief 读取obj文件并解析
 * @code UTF-8
 * @date 2023-12-23
 */
#include"wavefront_obj_parser.h"

using namespace std;
namespace XX_XZH{
WaveFrontOBJ WavefrontOBJParser(char* url)
{
  WaveFrontOBJ tmp_obj;
  ifstream obj_file;
  obj_file.open(url);
  if (!obj_file.is_open())
  {
    cerr << "文件打开失败" << endl;
    exit(0);
  }
  cout << "文件打开成功" << endl;
  char buff[100] = {};
  char *p, *q;
  int total_line = 0;
  while (obj_file.getline(buff, sizeof(buff)))
  { total_line++;
    // #号，代表注释，不用管
    if(buff[0] =='#'){
      continue;
    }
    // mtllib，存储到obj对应的mtllib中
    if (buff[0] == 'v' && buff[1] == ' ')
    {
      Vector3 tmp;
      tmp.SetX(strtod(buff + 2, &p));
      tmp.SetY(strtod(p, &p));
      tmp.SetZ(strtod(p, &p));
      tmp.OutPutVector3();
      tmp_obj.v.push_back(tmp);
    }
    if(buff[0]=='v' && buff[1] == 't'){
      Vector3 tmp;
      tmp.SetX(strtod(buff + 3, &p));
      tmp.SetY(strtod(p, &p));
      tmp.OutPutVector3();
      tmp_obj.vt.push_back(tmp);
    }
    if(buff[0]=='v' && buff[1] == 'n'){
      Vector3 tmp;
      tmp.SetX(strtod(buff + 3, &p));
      tmp.SetY(strtod(p, &p));
      tmp.SetZ(strtod(p, &p));
      tmp.OutPutVector3();
      tmp_obj.vn.push_back(tmp);
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
      tmp_face.OutputFace();
      tmp_obj.f.push_back(tmp_face);
    }
  }
  for (int i = 0; i < tmp_obj.v.size(); i++)
  {
    tmp_obj.v[i].OutPutVector3();
  }
  for (int i = 0; i < tmp_obj.f.size(); i++)
  {
    tmp_obj.f[i].OutputFace();
  }
  std::cout << total_line << std::endl;
  return tmp_obj;
}
}//namespace