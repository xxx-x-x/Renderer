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
    std::cout << vertex_index[0] << "/" << vertex_texture_index[0] << "/" << vertex_normal_index[0] << " " << vertex_index[1] << "/" << vertex_texture_index[1] << "/" << vertex_normal_index[1] << " " << vertex_index[2] << "/" << vertex_texture_index[2] << "/" << vertex_normal_index[2] << std::endl;
  }
}