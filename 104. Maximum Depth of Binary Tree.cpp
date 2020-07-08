#include <iostream>
#include <vector>
#include "Tree.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return leftDepth > rightDepth ? leftDepth + 1; rightDepth + 1;
    }

    int getMaxDepth(TreeNode* root, int deep) {
        if (root == nullptr) return 0;

        if (root->left == nullptr && root->right == nullptr)
            return 1;
        
        int leftDepth = getMaxDepth(root->left);
        int rightDepth = getMaxDepth(root->right);

        return leftDepth > rightDepth ? leftDepth + 1: rightDepth + 1;
    }
};

int main() {

}