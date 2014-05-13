/*
 * http://oj.leetcode.com/problems/swap-nodes-in-pairs/
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, 
 * only nodes itself can be changed.
 */
 
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) return NULL;
        if (head->next == NULL) return head;
        ListNode *p1, *p2, *p3, *p4 = NULL;
        p1 = head;
        head = NULL;
        while (p1) {
            p2 = p1->next;
            if (p2) {
                p3 = p2->next;
                p1->next = p3;
                p2->next = p1;
                if (p4) p4->next = p2;
            } else {
                p3 = NULL;
            }
            p4 = p1;
            p1 = p3;

            if (!head) head = p2;
        }
        return head;
    }
};
