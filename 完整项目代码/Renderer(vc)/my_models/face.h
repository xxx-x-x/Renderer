/**
 * @file face.h
 * @author 谢泽浩
 * 重构时间：2023-12-23
 * @brief 面片类
 * @code UTF-8
*/
#ifndef _FACE_H_
#define _FACE_H_
#include<vector>
#include<iostream>
#include"../my_math/my_math.h"
namespace XX_XZH{
  /**
   * 类注释：Face是面片类
   * 该类需要存储v，vt，vn的索引
  */
  enum IS_INSIDE {OUTSIDE=0,INSIDE,ONLINE};
  class Face{
    public:
      friend int DotInside(Face& tmp_face, std::vector<Vector3>& v,int& dot_x,int& dot_y);
      Face() = default;
      virtual ~Face() = default;
      void OutputFace()const;
      /** 函数注释：判断一个点是否在面内
       *  输入参数：顶点数组，判断点的坐标
      */
      int DotInside(std::vector<Vector3> v, float dot_x, float dot_y);
      //顶点索引
      std::vector<int> vertex_index;
      //顶点纹理索引
      std::vector<int> vertex_texture_index;
      //顶点法线索引
      std::vector<int> vertex_normal_index;
  };
  int DotInside(Face& tmp_face, std::vector<Vector3>& v,int& dot_x,int& dot_y);
}
#endif // !_FACE_H_