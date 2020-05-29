//
// Created by ermao on 2020/05/29.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int len = digits.size();

    for(int i = len - 1; i >= 0; --i) {
      ++digits[i];
      // 加1后不为10 ，直接返回结果
      if (digits[i] != 10) {
        return digits;
      }

      digits[i] = 0;
    }
    digits.insert(digits.begin(), 1);
    return digits;
  }
};