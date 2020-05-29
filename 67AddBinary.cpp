//
// Created by ermao on 2020/05/29.
//
#include <iostream>
#include <string>
using namespace std;

class Solution {
 public:
  string addBinary(string a, string b) {
    int len_a = a.length();
    int len_b = b.length();
    int i = len_a > len_b ? len_a-1 : len_b-1;
    string long_str = len_a >= len_b ? a: b;
    string short_str = len_a < len_b ? a: b;
    int long_len = long_str.length();
    int short_len = short_str.length();

    // 是否存在进位
    bool isNext = false;
    string result = "";

    for (i; i >= 0; --i) {
      if (long_len - i  > short_len) {
        if (long_str[i] == '1') {
          if (isNext) {
            isNext = true;
            result = "0" + result;
          } else {
            isNext = false;
            result = "1" + result;
          }
        } else {
          if (isNext) {
            isNext = false;
            result = "1" + result;
          } else {
            isNext = false;
            result = "0" + result;
          }
        }
        continue;
      }

      if (long_str[i] == '1' && short_str[i - (long_len - short_len)] == '1') {
        if (isNext)
          result = "1" + result;
        else
          result = "0" + result;
        isNext = true;
      } else if (long_str[i] == '0' && short_str[i - (long_len - short_len)] == '0') {
        if (isNext)
          result = "1" + result;
        else
          result = "0" + result;
        isNext = false;
      } else {
        if (isNext) {
          result = "0" + result;
          isNext = true;
        }
        else {
          result = "1" + result;
          isNext = false;
        }
      }
    }
    if (isNext) {
      result = "1" + result;
    }
    return result;
  }
};
int main() {
  string a = "1010";
  string b = "1011";
  Solution so = Solution();
  string re = so.addBinary(a, b);
  cout << re;
}