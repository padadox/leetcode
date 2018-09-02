
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
    TreeNode* increasingBST(TreeNode* root) {
        return trace(root).first;
    }

    pair<TreeNode*, TreeNode*> trace(TreeNode* root) {
        TreeNode* ans = root;
        TreeNode* last = root;

        if(root->left != NULL) {
            auto left = trace(root->left);
            ans = left.first;
            left.second->right = root;
            last = root;
        }

        if(root->right != NULL) {
            auto right = trace(root->right);
            root->right = right.first;
            last = right.second;
        }

        root->left = NULL;

        return make_pair(ans, last);
    }
};
