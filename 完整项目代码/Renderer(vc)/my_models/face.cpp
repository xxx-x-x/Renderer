/*
 * 文件名：face.cpp
 * 作者信息：谢泽浩
 * 重构时间：2023-12-18
 * 文件内容：模型最基础的三角面片
 * 编码格式：UTF-8
 * Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
 */
#include "face.h"
namespace XX_XZH
{
  void Face::OutputFace() const
  {
    for(int i=0;i<vertex_index.size();i++){
      std::cout << vertex_index[i] << "/" << (vertex_texture_index.size()>0? vertex_texture_index[i]: ' ') << "/" << (vertex_normal_index.size()>0? vertex_normal_index[i]: ' ') << " ";
    }
    std::cout << std::endl;
  }
  int Face::DotInside(std::vector<Vector3> v, float dot_x, float dot_y){
    std::vector<float> tmp_result;
    Vector2 dot_p(dot_x,dot_y);
    for(int i=0;i<vertex_index.size();i++){
      Vector2 vertex_sub_vertex = v[(i+1)%3] - v[i];
      Vector2 dot_p_sub_vertex = (Vector3)dot_p - v[i];
      tmp_result.push_back(Cross(vertex_sub_vertex,dot_p_sub_vertex));
    }
    return IS_EQUAL(tmp_result[0], tmp_result[1], tmp_result[2]) == true ? INSIDE:OUTSIDE;
  }
  int DotInsideUseCross(Face& tmp_face, std::vector<Vector3>& v,int& dot_x,int& dot_y){
    std::vector<float> tmp_result;
    Vector2 dot_p(dot_x,dot_y);
    for(int i=0;i<tmp_face.vertex_index.size();i++){
      Vector2 vertex_sub_vertex = v[(i+1)%3] - v[i];
      Vector2 dot_p_sub_vertex = (Vector3)dot_p - v[i];
      tmp_result.push_back(Cross(vertex_sub_vertex,dot_p_sub_vertex));
    }
    return IS_EQUAL(tmp_result[0], tmp_result[1], tmp_result[2]) == true ? INSIDE:OUTSIDE;
  }
}