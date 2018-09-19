#define CATCH_CONFIG_MAIN
#include "../../catch.hpp"
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
        vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
            stack<int> flag;
            stack<TreeNode*> s;
            s.push(root);
            flag.push(0);
            while(!s.empty()) {
                TreeNode* p = s.top();

                if(p == target) {
                    break;
                }

                auto &cur_flag = flag.top();
                flag.pop();
                if(0 == cur_flag) {
                    flag.push(1);
                    if(p->left != NULL) {
                        s.push(p->left);
                        flag.push(0);
                    }
                }
                else if(1 == cur_flag) {
                    flag.push(2);
                    if(p->right != NULL) {
                        s.push(p->right);
                        flag.push(0);
                    }
                }
                else {
                    s.pop();
                }
            }

            vector<int> ans;
            while(!s.empty()) {
                TreeNode* p = s.top();
                int cur_flag = flag.top();
                s.pop();
                flag.pop();
                trace(p, cur_flag, K, ans);
                K--;
                if(K < 0) {
                    break;
                }
            }

            return ans;
        }

        void trace(TreeNode* root, int flag, int n, vector<int>& ans) {
            if(n == 0) {
                ans.push_back(root->val);
                return;
            }
            queue<TreeNode*> q;
            queue<int> level;
            q.push(root);
            level.push(0);

            while(!q.empty()) {
                TreeNode* p = q.front();
                int lvl = level.front();
                q.pop();
                level.pop();

                lvl++;

                if(flag != 1 && p->left != NULL) {
                    if(lvl == n) {
                        ans.push_back(p->left->val);
                    }
                    else {
                        q.push(p->left);
                        level.push(lvl);
                    }
                }

                if(flag != 2 && p->right != NULL) {
                    if(lvl == n) {
                        ans.push_back(p->right->val);
                    }
                    else {
                        q.push(p->right);
                        level.push(lvl);
                    }
                }

                flag = 0;
            }
        }
};

TEST_CASE("leetcode", "binary_tree") {

    vector<string> vals{"0", "1", "null", "3", "2"};
    TreeNode *root = new TreeNode(atoi(vals[0].c_str()));
    queue<TreeNode*> q;
    vector<TreeNode*> nodes;
    nodes.push_back(root);
    q.push(root);
    for(int i = 1; i < vals.size(); i+=2) {
        TreeNode* p = q.front();
        q.pop();
        if(vals[i] != "null") {
            p->left = new TreeNode(atoi(vals[i].c_str()));
            q.push(p->left);
            nodes.push_back(p->left);
        }

        if(vals[i+1] != "null") {
            p->right = new TreeNode(atoi(vals[i+1].c_str()));
            q.push(p->right);
            nodes.push_back(p->right);
        }
    }

    Solution s;
    int target_val = 2;
    TreeNode* target = NULL;
    for(auto x: nodes) {
        if(x->val == target_val) {
            target = x;
        }
    }

    vector<int> ans = s.distanceK(root, target, 1);
    for(auto x: ans) {
        cout << x << " ";
    }
    cout << endl;

    for(auto x: nodes) {
        delete x;
    }

}
