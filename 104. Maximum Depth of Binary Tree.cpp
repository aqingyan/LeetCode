#include <iostream>
#include <vector>
#include "Tree.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // 当节点为NULL时，深度为0
        if (root == nullptr) return 0;
        
        // 当节点的左右子节点都为NULL时，说明只有一个节点，深度为1
        // 不过这块貌似可以优化掉，让递归到第一个if条件去
        // if (root->left == nullptr && root->right == nullptr)
        //     return 1;
        
        // 获取左子树深度
        int leftDepth = maxDepth(root->left);
        // 获取右子树深度
        int rightDepth = maxDepth(root->right);

        // 根据左右子树深度，返回最大的那个深度+1，+1是加上当前节点的
        return leftDepth > rightDepth ? leftDepth + 1:rightDepth + 1;
    }
};

int main() {

}