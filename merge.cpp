//
// Created by 18710 on 2020/06/18.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int i = 0;
        while (i < intervals.size()) {
            int left = intervals[i][0]; //获取左边界
            int right = intervals[i][1]; // 获取右边界
            int rightPoint = i + 1;  //右指针
            while (rightPoint < intervals.size() && intervals[rightPoint][0] <= right) {
                right = max(right, intervals[rightPoint][1]);
                rightPoint++;
            }
            ans.push_back({left, right});
            i = rightPoint;
        }
        return ans;
    }
};