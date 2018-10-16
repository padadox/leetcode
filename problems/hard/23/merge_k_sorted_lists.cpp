// 20181016 15:39
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
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include "../../../utils/utils.hxx"

/**
 * 方法1：
 * 迭代，每次merge一个list; 时间复杂度O(k^2*m), m是list的平均长度
 * 方法2：
 * 预先存储所有值，排序，输出list，时间复杂度O(N*logN), 空间复杂度O(N),  N = sum(n_i)
 * 方法3：
 * 类似merge sort, 每次两两合并，时间复杂度为O(km)
 *
 *
 */

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.empty()) {
                return nullptr;
            }
            int interval = 1;
            while(interval < lists.size()) {
                for(int i = 0; i + interval < lists.size(); i += interval*2) {
                    lists[i] = merge_two_lists(lists[i], lists[i+interval]);
                }

                interval *= 2;
            }

            return lists[0];
        }
    private:
        ListNode* merge_two_lists(ListNode* l1, ListNode* l2) {
            if(nullptr == l1) {
                return l2;
            }

            if(nullptr == l2) {
                return l1;
            }

            ListNode* ret = l1;
            if(l1->val >= l2->val) {
                ret = l2;
            }

            ListNode* pre = nullptr;
            for(; l2 != nullptr; ) {
                for(; l1 != nullptr && l1->val < l2->val; pre = l1, l1 = l1->next); 
                if(pre != nullptr) {
                    pre->next = l2;
                }
                if(l1 == nullptr) {
                    break;
                }
                pre = l2;
                l2 = l2->next;
                pre->next = l1;
            }

            return ret;
        }
};


int main(int argc, const char *argv[])
{
    vector<ListNode*> lists(5, nullptr);

    for(auto &x: lists) {
        string line;
        cin >> line;
        x = stringToListNode(line);
    }

    prettyPrintLinkedList(Solution().mergeKLists(lists));

    return 0;
}
