// 20181013 01:47
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


/*
 *
 *
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 方法:
 * 二分查找
 *
 */

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(NULL == root) {
            return 0;
        }

        int target = left_most_depth(root);
        int pos = 0;
        int ans = (1 << (target - 1)) - 1;
        while(--target && root != NULL) {
            pos <<= 1;
            if(left_most_depth(root->right) == target) {
                pos += 1;
                root = root->right;
            }
            else {
                root = root->left;
            }
        }

        ans += pos + 1;

        return ans;
    }

    // for complete tree, left most depth is depth
    int left_most_depth(TreeNode *root) {
        int ret = 0;
        while(root != NULL) {
            ret++;
            root = root->left;
        }

        return ret;
    }
};
