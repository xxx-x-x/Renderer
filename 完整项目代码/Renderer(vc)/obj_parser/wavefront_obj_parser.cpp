/**
 * @file wavefront_obj_parser.cpp
 * @author 谢泽浩
 * 重构时间：2023-12-23
 * @brief 读取obj文件并解析
 * @code UTF-8
 * @date 2023-12-23
*/
#ifndef _WAVEFRONT_OBJ_PARSER_H_
#define _WAVEFRONT_OBJ_PARSER_H_
#include<iostream>
#include<fstream>
#include<vector>
#include "../my_math/my_math.h"

using namespace std;
using namespace XX_XZH;

//v 中存放所有点坐标
vector<Vector3> v;
//f 面，存放点坐标顺序
vector<Vector3> f;
int main(int argc,char* argv[]){
    ifstream obj_file;
    obj_file.open(argv[1]);
    if(!obj_file.is_open()){
        cout<<"文件打开失败"<<endl;
        return 0;
    }
    cout << "文件打开成功" << endl;
    char buff[100] = {};
    char *p;
    while (obj_file.getline(buff, sizeof(buff)))
    {
        if (buff[0] == 'v' && buff[1] == ' ')
        {
            Vector3 tmp;
            tmp.SetX(strtod(buff + 2, &p));
            tmp.SetY(strtod(p, &p));
            tmp.SetZ(strtod(p, &p));
            v.push_back(tmp);
        }
        if(buff[0] == 'f' && buff[1] == ' '){
            Vector3 tmp;
            tmp.SetX(strtod(buff + 2, &p));
            tmp.SetY(strtod(p, &p));
            tmp.SetZ(strtod(p, &p));
            f.push_back(tmp);
        }
    }
    for(int i=0;i<v.size();i++){
        v[i].OutPutVector3();
    }
    for(int i=0;i<f.size();i++){
        f[i].OutPutVector3();
    }
    return 0;
}
#endif
