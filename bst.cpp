#include <iostream>
#include <stack>
#include <vector>
#include "Tree.h"

using namespace std;
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        result = iteration(root);
        return result;
    }
    
    vector<int> recursion(TreeNode* root, vector<int>& result) {
        if (root != nullptr) {
            result.push_back(root->val);
            recursion(root->left, result);
            recursion(root->right, result);
        }
        return result; 
    }
    
    vector<int> iteration(TreeNode* root) {
        stack<TreeNode*> stack;
        vector<int> result;
        while(!stack.empty() || root != nullptr) {
            while(root != nullptr) {
                result.push_back(root->val);
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            root = root->right;
        }
        return result;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        result = inorderRecursion(root, result);
        return result;
    }
    vector<int> inorderRecursion(TreeNode* root,vector<int> result) {
        if (root != nullptr) {
            result = inorderRecursion(root->left, result);
            result.push_back(root->val);
            result = inorderRecursion(root->right, result);
        }
        return result;
    }
    vector<int> inorderIteration(TreeNode* root, vector<int> result) {
        stack<TreeNode*> stack;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            result.push_back(root->val);
            stack.pop();
            root = root->right;
        }
        return result;
    }
};


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root) {
        if (root != NULL)
        {
            res.push_back(root->val);
            for(int i = 0; i < root->children.size(); ++i)
            {
                preorder(root->children[i]);
            }
        }
        return res;
    }
};