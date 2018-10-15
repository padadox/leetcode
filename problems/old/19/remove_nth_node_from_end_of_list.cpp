/*

Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            if(n == 0) {
                return head;
            }

            ListNode *nth_pre = head;
            ListNode *next = head->next;
            int cnt = 0;

            while (next != NULL) {
                next = next->next;
                cnt++;
                if(cnt > n) {
                    nth_pre = nth_pre->next;
                }
            }

            if(cnt < n) {
                ListNode* p = nth_pre->next;
                delete head;
                return p;
            }

            ListNode* p = nth_pre->next;
            nth_pre->next = p->next;
            delete p;

            return head;
        }
};
