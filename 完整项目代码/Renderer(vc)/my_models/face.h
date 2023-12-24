/**
 * @file face.h
 * @author 谢泽浩
 * 重构时间：2023-12-23
 * @brief 面片类
 * @code UTF-8
*/
#ifndef _FACE_H_
#define _FACE_H_
#include<iostream>
#include<vector>
#include"../my_math/my_math.h"
#include"../obj_parser/wavefront_obj_parser.h"
namespace XX_XZH{
  /**
   * 类注释：Face是面片类
   * 该类需要存储v，vt，vn的索引
  */
  class Face{
    public:
      Face() = default;
      virtual ~Face() = default;
      void OutputFace()const;
      friend const int DotInside(Face& tmp_face,const float dot_x,const float dot_y);
      //顶点索引
      std::vector<int> vertex_index;
      //顶点纹理索引
      std::vector<int> vertex_texture_index;
      //顶点法线索引
      std::vector<int> vertex_normal_index;
  };
  const int DotInside(Face& tmp_face,const float dot_x,const float dot_y);
}
#endif // !_FACE_H_