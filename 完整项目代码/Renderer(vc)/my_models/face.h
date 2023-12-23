/**
 * @file face.h
 * @author 谢泽浩
 * 重构时间：2023-12-23
 * @brief 面片类
 * @code UTF-8
*/
#ifndef _FACE_H_
#define _FACE_H_

namespace XX_XZH{
  /**
   * 类注释：Face是面片类
   * 该类用来存储三角面片的顶点索引 和 顺序
  */
  class Face{
    public:
    private:
      int vertex_index[3];
  };
}
#endif // !_FACE_H_