#include"stdio.h"
#include<iostream>
#include<fstream>
#include"wavefront_obj_parser.h"
#include"../my_models/wavefront_obj.h"
using namespace XX_XZH;
int main(){
  WaveFrontOBJ tmp_obj;
  char url[100] = "./obj_model/triangle.obj";
  tmp_obj=WavefrontOBJParser(url);
  tmp_obj.OutputWaveFrontOBJ();
}