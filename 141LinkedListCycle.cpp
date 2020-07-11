/*
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.
*/

#include <iostream>
#include <vector>
#include "Tree.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 通过快慢指针，如果有环，两者总会相遇
     */
    bool hasCycle(ListNode *head) {
        ListNode *slow, *fast;
        if (head == NULL || head->next == NULL) return false;
        slow = head;
        fast = head->next;

        // 因为快指针比慢指针走的多，所以有可能先遇到NULL，慢指针就不需要做判断了
        while (fast != NULL && fast->next != NULL)
        {
            if (slow == fast)
                return true;
            // 1 step
            slow = slow->next;
            // 2 steps
            fast = fast->next->next;
        }
        return false;
    }
    /**
     * 哈希
    */
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> hash;
        ListNode* node;
        node = head;
        while (node != NULL)
        {
            if (hash.find(node) != hash.end())
                return true;
            hash[node] = 1;
            node = node->next;
        }
        return false;
    }
};

