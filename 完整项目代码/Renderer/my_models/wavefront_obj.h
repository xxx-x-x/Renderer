/**
 * @file wavefron_obj.h
 * @author 谢泽浩
 * 重构时间：2023-12-25
 * @brief 模型类
 * @code UTF-8
*/
#ifndef _WAVEFRONT_OBJ_H_
#define _WAVEFRONT_OBJ_H_
#include<vector>
#include"face.h"
#include"../my_math/my_math.h"
namespace XX_XZH
{
/**
 * 类注释：该类为模型类，.obj文件解析后应该存储在该类中
 * v数组,用来存放所有顶点坐标
 * vt数组,用来存放所有顶点材质坐标
 * vn数组,用来存放所有顶点法线
 * f数组,用来存放所有的面
 * usemtl,用来存储材质路径
*/
class WaveFrontOBJ{
  public:
    WaveFrontOBJ();
    virtual ~WaveFrontOBJ() = default;
    void OutputWaveFrontOBJ();
    std::vector<Vector3> v; 
    std::vector<Vector3> vt;
    std::vector<Vector3> vn;
    std::vector<Face> f;
    char usemtl[100];
    char mtllib[100];
};
} // namespace XX_XZH
#endif