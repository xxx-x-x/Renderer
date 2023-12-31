/**
 * @file wavefront_obj_parser.h
 * @author 谢泽浩
 * 重构时间：2023-12-23
 * @brief 读取obj文件并解析
 * @code UTF-8
 * @date 2023-12-23
 */
#ifndef _WAVEFRONT_OBJ_PARSER_H_
#define _WAVEFRONT_OBJ_PARSER_H_

#include <iostream>
#include <fstream>
#include <vector>
#include "../my_math/my_math.h"
#include "../my_models/face.h"
#include"../my_models/wavefront_obj.h"
#include"../my_math/my_math.h"
namespace XX_XZH{
  WaveFrontOBJ WavefrontOBJParser(char* url);
}
#endif