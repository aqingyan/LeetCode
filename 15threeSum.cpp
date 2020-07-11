#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 三数和：
     * 先取第一个，之后可以转换为求2数和
     * 时间复杂度：O(n^2)
     * 空间复杂度：O(n)?
     * 需要注意的是：当相等时，记得对头尾指针进行递增或者递减
     */ 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;        
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i)
        {
            int left = i + 1, right = nums.size() - 1;
            int target = 0 - nums[i];

            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    vector<int> ans;
                    ans.push_back(nums[i]);
                    ans.push_back(nums[left]);
                    ans.push_back(nums[right]);
                    result.push_back(ans);
                    
                    //防止第二个数字重复
                    while (left < right && nums[left] == ans[1])
                        ++left;
                    
                    //防止第三个数字重复
                    while (left < right && nums[right] == ans[2])
                        --right;
                }
                else
                {
                    sum < target ? ++left : --right;
                }
            }
            //防止第一个数字重复
            while (nums[i] == nums[i + 1] && i < nums.size() - 1)
                ++i;
        }
        return result;
    }

};

int main() {
    Solution S;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans;
    ans = S.threeSum(nums);
    for (int i = 0; i < ans.size(); ++i)
    {
        for (int j = 0; j < ans[i].size(); ++j)
        {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
}