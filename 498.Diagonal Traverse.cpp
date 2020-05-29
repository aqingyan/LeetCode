//
// Created by ermao on 2020/05/29.
//
// 给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。
#include <iostream>
#include <vector>
using  namespace std;

class Solution {
 public:
  vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
    // 数据长度
    int len = matrix.size();
    // 遍历方向，起始值向右
    bool up = true;
    // 矩阵索引值, x + y = i
    int x = 0, y = 0;
    // 输出结果
    vector<int> result;
    // 开始循环
    for (int i = 0; i < len; ++i) {

      while (x + y <= i && x >=0 && y >= 0) {
        cout << matrix[x][y] << endl;
        // 控制方向
        if (up == true)
          ++y;
        else
          --y;
        x = i - y;
        if (x < 0)
          x = 0;
        if (y < 0)
          y = 0;
      }
      if (up == true)
        up = false;
    }
  }
};

int main(){

}