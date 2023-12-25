/**
 * @file wavefront_obj.cpp
 * @author 谢泽浩
 * 重构时间：2023-12-23
 * @brief  模型类
 * @code UTF-8
*/
#include"wavefront_obj.h"
namespace XX_XZH{
  WaveFrontOBJ::WaveFrontOBJ(){
    char usemtl[100] = "null";
  }
  void WaveFrontOBJ::OutputWaveFrontOBJ(){
    for(std::vector<Vector3>::iterator it = v.begin();it!=v.end();it++){
      std::cout << "v "; (*it).OutPutVector3();
    }
    for(std::vector<Vector3>::iterator it = vt.begin();it!=vt.end();it++){
      std::cout << "vt "; (*it).OutPutVector3();
    }
    for(std::vector<Vector3>::iterator it = vn.begin();it!=vn.end();it++){
      std::cout <<"vn ";(*it).OutPutVector3();
    }
    for(std::vector<Face>::iterator it = f.begin();it!=f.end();it++){
      std::cout<<"f ";(*it).OutputFace();
    }
    std::cout<< std::endl << usemtl << std::endl;
  }
  const int WaveFrontOBJ::DotInside(const float dot_x,const float dot_y){

  }
}