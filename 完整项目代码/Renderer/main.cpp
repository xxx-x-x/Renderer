// compile with: /D_UNICODE /DUNICODE /DWIN32 /D_WINDOWS /c

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <string.h>
#include<string>
#include"my_math/my_math.h"
#include"my_tools/my_tools.h"
#include"my_models/my_triangle.h"

#define MAX_WIDTH 500
#define MAX_HEIGHT 500
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

//函数前置声明
float fps;
int DrawPicture(HWND hWnd);
int WINAPI WinMain(
  _In_ HINSTANCE hInstance,
  _In_opt_ HINSTANCE hPrevInstance,
  _In_ LPSTR     lpCmdLine,
  _In_ int       nCmdShow
)
{
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
    MessageBox(NULL,
      _T("Call to RegisterClassEx failed!"),
      _T("Windows Desktop Guided Tour"),
      NULL);

    return 1;
  }

  // Store instance handle in our global variable
  hInst = hInstance;

  // The parameters to CreateWindowEx explained:
  // WS_EX_OVERLAPPEDWINDOW : An optional extended window style.
  // szWindowClass: the name of the application
  // szTitle: the text that appears in the title bar
  // WS_OVERLAPPEDWINDOW: the type of window to create
  // CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
  // 500, 100: initial size (width, length)
  // NULL: the parent of this window
  // NULL: this application does not have a menu bar
  // hInstance: the first parameter from WinMain
  // NULL: not used in this application
  HWND hWnd = CreateWindowEx(
    WS_EX_OVERLAPPEDWINDOW,
    szWindowClass,
    szTitle,
    WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT,
    MAX_WIDTH, MAX_HEIGHT,
    NULL,
    NULL,
    hInstance,
    NULL
  );

  if (!hWnd)
  {
    MessageBox(NULL,
      _T("Call to CreateWindow failed!"),
      _T("Windows Desktop Guided Tour"),
      NULL);

    return 1;
  }
  // The parameters to ShowWindow explained:
  // hWnd: the value returned from CreateWindow
  // nCmdShow: the fourth parameter from WinMain
  ShowWindow(hWnd,
    nCmdShow);
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
  DWORD start, stop;
  //如果尝试无缓冲，请删除双斜杠
  //Vector2 v1(100, 100);
  //Vector2 v2(300, 300);
  //Vector2 v3(300, 100);
  //Triangle tri(v1, v2, v3);

  switch (message)
  {
  case WM_PAINT:
    //开始统计帧数
    start = clock();
    //如果尝试无缓冲，请删除双斜杠
    //DrawLineUseDDAv1(hdc, v2, v1);
    //DrawLineUseDDAv1(hdc, v1, v3);
    //DrawLineUseDDAv1(hdc, v2, v3);
    //DrawTriangleUseAABB(hdc, tri);
    hdc = BeginPaint(hWnd, &ps);
    //如果尝试无缓冲，请将DrawPicture函数注释掉
    DrawPicture(hWnd);
    //统计结束帧数
    stop = clock();
    //stop - start 得到这一帧的时间
    //1000 / (stop - start) 一秒除以时间得到这一帧的帧率
    fps = (stop - start)*1000/CLOCKS_PER_SEC;
    wchar_t cha[10];
    _itow_s(fps, cha, 10, 10);
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

int DrawPicture(HWND hWnd) {
  /*开始双缓冲算法实现*/  
  //得到屏幕设备上下文
  HDC WindowsDC = GetDC(hWnd);
  //创建一个内存设备上下文
  HDC MemoryDC = CreateCompatibleDC(WindowsDC);
  //如果内存DC创建失败，打印消息
  if (MemoryDC == 0) {
    MessageBox(NULL,
      _T("Call to CreateCompatibleDC failed!"),
      _T("Windows Desktop Guided Tour"),
      NULL);
  }
  //创建一个内存位图
  HBITMAP MemoryBitmap = CreateCompatibleBitmap(WindowsDC, MAX_WIDTH, MAX_HEIGHT);
  //将位图选入内存设备上下文,保存旧位图
  SelectObject(MemoryDC, MemoryBitmap);

  //画图区域--------------------------------------------------
  //画图区域--------------------------------------------------
  //区域填充颜色
  FillRect(MemoryDC, new RECT{ 0,0,MAX_WIDTH,MAX_HEIGHT }, (HBRUSH)(COLOR_WINDOW + 1));
  //在内存位图上绘制
  Vector2 v1(100, 100);
  Vector2 v2(300, 300);
  Vector2 v3(300, 100);
  Triangle tri(v1, v2, v3);
  //测试，画一个线框
  DrawLineUseDDAv1(MemoryDC, v2, v1);
  DrawLineUseDDAv1(MemoryDC, v1, v3);
  DrawLineUseDDAv1(MemoryDC, v2, v3);
  DrawTriangleUseAABB(MemoryDC, tri);
  //画图区域--------------------------------------------------
  //画图区域--------------------------------------------------
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
