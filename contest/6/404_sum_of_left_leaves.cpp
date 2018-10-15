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

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();


/*
 *404. Sum of Left Leaves
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24
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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(NULL == root) {
            return 0;
        }

        int sum = 0;
        queue<TreeNode*> q;
        queue<char> flag;

        q.push(root);
        flag.push(0);

        while(!q.empty()) {
            TreeNode* cur = q.front();
            char cur_flag = flag.front();
            q.pop();
            flag.pop();

            if(cur->left == NULL && cur->right == NULL) {
                if(cur_flag == 1) {
                    sum += cur->val;
                }

                continue;
            }

            if(cur->left != NULL) {
                q.push(cur->left);
                flag.push(1);
            }

            if(cur->right != NULL) {
                q.push(cur->right);
                flag.push(2);
            }
        }

        return sum;
    }
};
