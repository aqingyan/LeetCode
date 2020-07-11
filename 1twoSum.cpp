#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        return twoSumByPoint(nums, target);
    }
    /**
     * 哈希解法
     * 创建一个map，每次循环检查差值是否在map中存在
     * 存在，说明找到对应的值，返回当前位置的索引以及map中差值对应的索引
     * 不存在，将当前位置的值作为key，索引作为值放入map中，用于下次
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    vector<int> twoSumByHash(vector<int>& nums, int target) {
        map<int, int> dic;
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            int temp;
            temp = target - nums[i];
            if (dic.find(temp) != dic.end()) 
            {
                ans.push_back(dic[temp]);
                ans.push_back(i);
                break;
            }
            dic[nums[i]] = i;
        }
        return ans;
    }
    /**
     * 排序 + 双指针
     * 先将数据排序，通过头尾双指针的方式，判断头指针所指与尾指针所指是否与目标一致
     * 大于则尾部前移
     * 小于则头部后移
     * 注意：此时排序后，原来的下标位置已经改变了，所以需要将排序后获取的数字与原始数据比较
     * 获得原始下标
     */
    vector<int> twoSumByPoint(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> numsCopy = nums, ans;

        sort(numsCopy.begin(), numsCopy.end());
        while (left < right) 
        {
            if (numsCopy[left] + numsCopy[right] == target)
                break;
            (numsCopy[left] + numsCopy[right] > target) ? right-- : left++;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (numsCopy[left] == nums[i] || numsCopy[right] == nums[i])
                ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    vector<int> nums = {3,2,4};
    int target = 6;
    Solution S;
    vector<int> ans = S.twoSum(nums, target);
    for (size_t i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}