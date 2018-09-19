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

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int m = numeric_limits<int>::max();
public:
    int getMinimumDifference(TreeNode* root) {
        trace(root);
        return m;
    }

    pair<int, int> trace(TreeNode* root) {
        int right_v = root->val;
        int left_v = root->val;
        if(root->right != NULL) {
            auto r = trace(root->right);
            right_v = r.second;
            m = min(m, r.first - root->val);
        }

        if(root->left != NULL) {
            auto l = trace(root->left);
            left_v = l.first;
            m = min(m, root->val - l.second);
        }

        return make_pair(left_v, right_v);
    }
};
