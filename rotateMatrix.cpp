#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        auto new_matrix = matrix;
        // 根据旋转计算出规律，定义旋转过后的坐标为n,m
        // 可以算出 n = j，m = N - i - 1 ，N为矩阵大小
        // 之后新增辅助空间进行赋值，也可以原地旋转
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                // new_matrix[n][m] = matrix[j][N-i-1]

                new_matrix[j][N - 1 - i] = matrix[i][j];
            }
        }
        matrix = new_matrix;
    }
    //先对角转再翻转
    void rotate_2(vector<vector<int>>& matrix) {
        int N = matrix.size();

        //对角线旋转，相当于旋转180°
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //再还原90°，左右翻转
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N/2; ++j) {
                swap(matrix[i][j], matrix[i][N-1-j]);
            }
        }
    }
};


int main() {
    Solution Solu = Solution();
    vector<vector<int>> matrix = {
  {1,2,3},
  {4,5,6},
  {7,8,9}
    };
    Solu.rotate_2(matrix);
    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 3; j++)
            cout << matrix[i][j];
        cout << endl;
    }
}
