// 20181017 15:32
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#define pb push_back
#define fst first
#define snd second

using int64 = long long;
using pii = pair<int,int>;
using tiii = tuple<int, int, int>;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const int64 MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();



/**
 *
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include "../../../utils/utils.hxx"

/*
 * 方法1:
 * 先找的k个值，然后翻转；
 * 方法2: 
 * 翻转，每k个一组，最后不足k个，则翻转回来。
 *
 * 视k大小，两种方法可能存在效率差异。
 */

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if(k <= 1) {
                return head;
            }

            ListNode ret(0);
            ListNode *pre_last = &ret;
            ListNode *pre = pre_last;
            ListNode *first = head;
            ListNode *cur = first;

            int i = 0;
            for (; cur != nullptr; )
            {
                ListNode *tmp = cur->next;
                cur->next = pre;
                i++;

                if(i < k) {
                    pre = cur;
                    cur = tmp;
                    continue;
                }

                pre_last->next = cur;
                pre_last = first;
                pre = first;
                pre->next = nullptr;
                first = tmp;
                cur = first;
                i = 0;
            }

            if(i != 0) {
                cur = pre;
                pre = nullptr;
                for(; pre != pre_last; ) {
                    ListNode *tmp = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = tmp;
                }
            }

            return ret.next;
        }
};

int main(int argc, const char *argv[])
{
    while(true) {
        string s;
        cin >> s;
        if(s == "q") {
            break;
        }

        int k = 0;
        cin >> k;

        ListNode* head = stringToListNode(s);
        ListNode* ret = Solution().reverseKGroup(head, k);
        prettyPrintLinkedList(ret);
    }
    
    return 0;
}
