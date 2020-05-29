//
// Created by ermao on 2020/05/29.
//

#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
  int strStr(string haystack, string needle) {
    if (needle == "")
      return 0;

    int len_needle = needle.length();
    int len_haystack = haystack.length();
    // 子串大于原串，子串长度等于原串且子串不等于原串直接返回-1
    if (len_needle > len_haystack || (len_needle == len_haystack && haystack != needle))
      return -1;
    if (haystack == needle)
      return 0;

    // 循环查找
    for (int i = 0; (i + len_needle) <= len_haystack; ++i) {
      if (haystack.substr(i, len_needle) == needle)
        return i;
    }
    return -1;
  }
};
int main() {
  string haystack = "mississippi";
  string needle = "pi";
  Solution so = Solution();
  int re = so.strStr(haystack, needle);
  cout << re;
}
