/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/swap-nodes-in-pairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include "List.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *firstNode, *secondNode, *prevNode, *newHead = new ListNode(NULL);
        prevNode = newHead;
        while (head && head->next)
        {
            firstNode = head;
            secondNode = head->next;

            prevNode->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            prevNode = firstNode;
            head = firstNode->next;
        }
        return newHead->next;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *firstNode, *secondNode;
        
        firstNode = head;
        secondNode = head->next;

        firstNode->next = swapPairs(secondNode->next);
        secondNode->next = firstNode;
             
        return secondNode;
    }
};
