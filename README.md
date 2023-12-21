# Renderer
## 一、创建窗口

 	1. 开发环境：Visual Studio 2022
 	2. 桌面环境：Windows10
 	3. 项目类型：Windows桌面向导，确保选择桌面应用程序，附加选项勾选空项目
 	4. 代码参考：[此处代码创建一个窗口](https://github.com/xxx-x-x/Renderer/blob/main/Task2-%E7%BC%96%E5%86%99Win%E7%AA%97%E5%8F%A3/main.cpp)

## 二、数学库的编写



## 三、工具类的编写

## 四、编写模型类

## 五、双缓冲算法

​	当不使用任何缓冲算法时，绘制函数将直接在**`显示设备上下文`**上进行绘制。在慢放过程中，可以明显观测到绘制过程。当片元发生移动、旋转、缩放时，可以明显观测到锯齿边缘的抖动。

​	当使用双缓冲算法时，绘制函数将在**`内存设备上下文`**中进行绘制，绘制完成后**整体**拷贝到**`显示设备上下文`**中。在慢放过程中，可以明显观测到一次性绘制完成。当片元发生移动、旋转、缩放时，并不能明显观测到锯齿。

### 5.1 内存设备上下文

​	若要使应用程序能够将输出置于内存中，而不是将其发送到实际设备，请使用特殊的设备上下文进行位图操作，称为 **`内存设备上下文`**。 内存 DC 使系统能够将部分内存视为虚拟设备。 它是内存中的一个位数组，应用程序可以暂时使用该数组来存储在普通绘图图面上创建的位图的颜色数据。 由于位图与设备兼容，因此内存 DC 有时也称为**`兼容的设备上下文`**。

### 5.2 位图

​	内存 DC 存储特定设备的位图图像。 应用程序可以通过调用 [**CreateCompatibleDC**](https://learn.microsoft.com/zh-cn/windows/desktop/api/Wingdi/nf-wingdi-createcompatibledc) 函数来创建内存 DC。

​	内存 DC 中的原始位图只是占位符。 其尺寸是一个像素乘以一个像素。 应用程序必须通过调用 [**SelectObject**](https://learn.microsoft.com/zh-cn/windows/desktop/api/Wingdi/nf-wingdi-selectobject) 函数来选择具有适当宽度和高度的位图，然后应用程序才能开始绘制 DC。 若要创建相应维度的位图，请使用 [**CreateBitmap**](https://learn.microsoft.com/zh-cn/windows/desktop/api/Wingdi/nf-wingdi-createbitmap) 函数。 将位图选入内存 DC 后，系统会将单位数组替换为足够大的数组，以存储指定像素矩形的颜色信息。

​	当应用程序将 [**CreateCompatibleDC**](https://learn.microsoft.com/zh-cn/windows/desktop/api/Wingdi/nf-wingdi-createcompatibledc) 返回的句柄传递给绘图函数之一时，请求的输出不会显示在设备的绘图图面上。 相反，系统会将生成的线条、曲线、文本或区域的颜色信息存储在位数组中。 应用程序可以通过调用 [**BitBlt**](https://learn.microsoft.com/zh-cn/windows/desktop/api/Wingdi/nf-wingdi-bitblt) 函数，将内存 DC 标识为源设备上下文，将窗口或屏幕 DC 标识为目标设备上下文，将存储在内存中的图像复制回绘图图面。

### 5.3 双缓冲原理

​	通过屏幕HWND获取到屏幕DC，然后通过屏幕DC创建兼容的内存DC，我们还需要根据屏幕DC来创建一个内存位图，将内存位图选入内存DC中，然后我们在内存DC中（其实是画在内存位图上的，但是需要使用DC句柄）进行绘制，再将绘制结果拷贝到屏幕DC上，消息循环中，将屏幕DC中的内容绘制出来

​	

#### 参考文献：

1. [GAMES101-现代计算机图形学入门-闫令琪](https://www.bilibili.com/video/BV1X7411F744/?spm_id_from=333.337.search-card.all.click&vd_source=26caf3f7dc50266646d431ae50462531)
2. [计算机图形学系列笔记](https://www.zhihu.com/column/c_1249465121615204352)
3. [演练：创建Windows桌面应用程序](https://learn.microsoft.com/zh-cn/cpp/windows/walkthrough-creating-windows-desktop-applications-cpp?view=msvc-170)
4. [DeleteDC() ReleaseDC()和DeleteObject()之间的区别](https://blog.csdn.net/oyhb_1992/article/details/78794217)
5. [位图，设备上下文和BitBlt](http://winprog.org/tutorial/zh/bitmaps_cn.html)
6. [releaseDC函数](https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-releasedc)

