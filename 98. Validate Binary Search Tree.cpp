#include <iostream>
#include <climits>
#include <stack>
#include "Tree.h"
using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    bool helper(TreeNode* root, long long min, long long max) {
        // 空树也是二叉搜索树
        if (root == nullptr) return true;
        // 当前节点比最小小或比最大大，说明子树搜索树，false
        if (root->val >= max || root->val <= min) return false;
        // 判断左右子树
        bool left = helper(root->left, min, root->val);
        bool right = helper(root->right, root->val, max);

        return left && right;
    }

    
};

bool isValidBST(TreeNode* root) {
    //中序遍历，既然是二叉搜索树，那么中序遍历的结果是升序的，只要比较当前值与前一个值大小即可
    stack<TreeNode*> st;
    long long prev = (long long)INT_MIN - 1;
    while(!st.empty() || root != nullptr) {
        while(root != nullptr) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if (root->val <= prev) return false;
        prev = root->val;
        root = root->right;
    }
    return true;
}

