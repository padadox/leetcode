/*
 Virtual User Accepted: 0
Virtual User Tried: 0
Virtual Total Accepted: 0
Virtual Total Submissions: 0
Difficulty: Easy
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.



For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

 

Note:

Both of the given trees will have between 1 and 100 nodes.*
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

#include <vector>
#include <stack>
#include <cstdlib>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        void trace(TreeNode* root, vector<int>& s) {

            stack<TreeNode*> q;
            if(root == NULL) {
                return;
            } 

            unordered_map<TreeNode*, int> flag;

            q.push(root);
            while(!q.empty()) {
                TreeNode* c = q.top();
                if(c->left == NULL && c->right == NULL) {
                    s.push_back(c->val);
                    q.pop();
                    continue;
                }

                if(flag[c] == 2) {
                    q.pop();
                    continue;
                }

                if(flag[c] == 0 && c->left != NULL) {
                    flag[c] = 1;
                    q.push(c->left);
                    flag[c->left] = 0;
                }
                else {
                    flag[c] = 2;
                    if(c->right != NULL) {
                        q.push(c->right);
                        flag[c->right] = 0;
                    }
                }
            }
        }

        bool leafSimilar(TreeNode* root1, TreeNode* root2) {
            vector<int> s1;
            vector<int> s2;

            trace(root1, s1);
            trace(root2, s2);

            if(s1.size() != s2.size()) {
                return false;
            }

            for(size_t i = 0; i < s1.size(); ++i) {
                if(s1[i] != s2[i]) {
                    return false;
                }
            }

            return true;
        }
};
