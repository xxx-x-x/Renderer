
/*
* 文件名：face.cpp
* 作者信息：谢泽浩
* 重构时间：2023-12-18
* 文件内容：模型最基础的三角面片
* 编码格式：UTF-8
* Copyright 2023 - 2099 xx-xzh.All Rights Reserved.
*/
#include"face.h"
namespace XX_XZH{
    void Face::OutputFace()const{
        std::cout << "f " << vertex_index[0] << "/"<<vertex_texture_index[0]<<"/"<<vertex_normal_index[0] << " " << vertex_index[1] << "/"<<vertex_texture_index[1]<<"/"<<vertex_normal_index[1]<< " " <<  vertex_index[2] << "/"<<vertex_texture_index[2]<<"/"<<vertex_normal_index[2] << std::endl;
    }
    const int DotInside(Face& tmp_face,const float dot_x,const float dot_y){
        std::vector<float> tmp_result;
        Vector2 dot_p(dot_x,dot_y);
        for(int i=0;i<3;i++){
            Vector2 vertex_sub_vertex ;
        }
    }
}