// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <iostream>
#include <ctime>
#include"my_math/my_math.h"
#include"my_tools/my_tools.h"
#include"my_models/wavefront_obj.h"
#include"my_models/face.h"
#include"obj_parser/wavefront_obj_parser.h"

#define MAX_WIDTH 800
#define MAX_HEIGHT 800
#define CLOCKS_PER_SEC 1000
using namespace XX_XZH;
// Global variables

// The main window class name.
static TCHAR szWindowClass[] = _T("https://halo.xx-xzh.xyz");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("https://halo.xx-xzh.xyz");

// Stored instance handle for use in Win32 API calls such as FindResource
HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//全局变量声明区域
float fps;
Matrix Model;
Matrix View;
Matrix Project;
Matrix ViewPort;
float *zbuffer = new float[MAX_HEIGHT * MAX_WIDTH];
Vector3 light_dir;
std::vector<WaveFrontOBJ> arr_obj;
std::vector<WaveFrontOBJ> arr_obj_origin;
//全局函数前置声明
int DrawPicture(HWND hWnd,WaveFrontOBJ& obj);
int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR     lpCmdLine,_In_ int       nCmdShow)
{
  //加载一个模型
  WaveFrontOBJ tmp_obj;
  //char url[100] = "./obj_model/Sting-Sword-lowpoly.obj";
  //char url[100] = "./obj_model/triangle.obj";
  char url[100] = "./obj_model/african_head.obj";
  tmp_obj = WavefrontOBJParser(url);
  arr_obj.push_back(tmp_obj);
  arr_obj_origin.push_back(tmp_obj);
  std::cout << "模型加载完毕" <<std::endl;
  //模型坐标系变换
  Model.ModelTranslation(0, 0, 0);
  View.ViewMatrix(0,0,1.5,0,0,-1,0,1,0);
  Project.ProjectionMatrix(1,-1,-1,-2,1,-1);
  ViewPort.ViewportMatrix(MAX_WIDTH,MAX_HEIGHT);
  //第一步，加载所有模型
  for(int i=0;i<arr_obj.size();i++){
    //第二步，加载模型上，所有的点
    for(int j=0;j<arr_obj[i].v.size();j++){
      arr_obj[i].v[j] = (ViewPort * Project * View * Model * arr_obj[i].v[j]).Identity();
    }
  }
  light_dir = Vector3(0,0,-1) - Vector3(0,0,0);
  light_dir.Normalize();
  for (int i=MAX_HEIGHT * MAX_WIDTH; i--; zbuffer[i] = -100000);
  std::cout << "灯光初始化完毕" <<std::endl;
  WNDCLASSEX wcex;
  wcex.cbSize = sizeof(WNDCLASSEX);
  wcex.style = CS_HREDRAW | CS_VREDRAW;
  wcex.lpfnWndProc = WndProc;
  wcex.cbClsExtra = 0;
  wcex.cbWndExtra = 0;
  wcex.hInstance = hInstance;
  wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
  wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wcex.lpszMenuName = NULL;
  wcex.lpszClassName = szWindowClass;
  wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);
  if (!RegisterClassEx(&wcex))
  {
    MessageBox(NULL,_T("Call to RegisterClassEx failed!"),_T("Windows Desktop Guided Tour"),NULL);
    return 1;
  }
  hInst = hInstance;
  HWND hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW,szWindowClass,szTitle,WS_OVERLAPPEDWINDOW,CW_USEDEFAULT, CW_USEDEFAULT,MAX_WIDTH, MAX_HEIGHT,NULL,NULL,hInstance,NULL);
  if (!hWnd)
  {
    MessageBox(NULL,_T("Call to CreateWindow failed!"),_T("Windows Desktop Guided Tour"),NULL);
    return 1;
  }
  ShowWindow(hWnd,nCmdShow);
  UpdateWindow(hWnd);
   // Main message loop:
  MSG msg;
  while (GetMessage(&msg, NULL, 0, 0))
  {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return (int)msg.wParam;
}

//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  PAINTSTRUCT ps;
  HDC hdc;
  clock_t start,stop;
  switch (message)
  {
  case WM_PAINT:
    //开始统计帧数
    start = clock();
    hdc = BeginPaint(hWnd, &ps);
    //如果尝试无缓冲，请将DrawPicture函数注释掉
    DrawPicture(hWnd,arr_obj[0]);
    //统计结束帧数
    stop = clock();
    //stop - start 得到这一帧的时间
    //1000 / (stop - start) 一秒除以时间得到这一帧的帧率
    fps = CLOCKS_PER_SEC / (stop - start);
    TCHAR cha[16];
    _itot(fps,cha,10);
    TextOut(hdc,5, 5,cha, _tcslen(cha));

    ReleaseDC(hWnd, hdc);
    EndPaint(hWnd, &ps);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);
    break;
  default:
    return DefWindowProc(hWnd, message, wParam, lParam);
    break;
  }

  return 0;
}
/**函数注释：双缓冲算法实现的绘图
 * 函数输入：变换后的点坐标和面
*/
int DrawPicture(HWND hWnd,WaveFrontOBJ& obj) {
  /*开始双缓冲算法实现*/  
  //得到屏幕设备上下文
  HDC WindowsDC = GetDC(hWnd);
  //创建一个内存设备上下文
  HDC MemoryDC = CreateCompatibleDC(WindowsDC);
  //创建一个内存位图
  HBITMAP MemoryBitmap = CreateCompatibleBitmap(WindowsDC, MAX_WIDTH, MAX_HEIGHT);
  //将位图选入内存设备上下文,保存旧位图
  if (MemoryDC != NULL) {
    SelectObject(MemoryDC, MemoryBitmap);
  }
  //区域填充颜色
  if (MemoryDC != NULL) {
    FillRect(MemoryDC, new RECT{ 0,0,MAX_WIDTH,MAX_HEIGHT }, (HBRUSH)(COLOR_WINDOW + 1));
  }
  //加载模型的面
  for(int i=0;i<obj.f.size();i++){
    //obj].f[i] 中存放了顶点的顺序，按照顺序绘图即可
    //！！注意，索引值是比数组下标大一的
    std::vector<int> tmp_index = obj.f[i].vertex_index;
    //DrawFaceUseLine(MemoryDC,obj.v[tmp_index[0]-1],obj.v[tmp_index[1]-1],obj.v[tmp_index[2]-1],RGB(0,0,255));
    //背面剔除
    Vector3 face_normal = FaceNormal(obj.f[i],arr_obj_origin[0].v);
    double intensity = face_normal*light_dir;
    if(face_normal.GetZ()<0){
      DrawFaceUseBarycentricAABB(MemoryDC,zbuffer,i,obj,intensity);
    }
  }
  //DrawTriangleUseAABB(MemoryDC, tri);
  //将内存DC到主DC1上
  BitBlt(WindowsDC, 0, 0, MAX_WIDTH, MAX_HEIGHT, MemoryDC, 0, 0, SRCCOPY);
  //删除内存位图
  DeleteObject(MemoryBitmap);
  //删除内存设备上下文
  DeleteObject(MemoryDC);
  //释放屏幕设备上下文
  ReleaseDC(hWnd, WindowsDC);
  return 0;
}
