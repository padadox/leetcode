
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
        vector<TreeNode*> allPossibleFBT(int N) {
            vector<TreeNode*> ans;
            if(N % 2 == 0) {
                return ans;
            }

            vector<vector<TreeNode*>> all(N+1);
            TreeNode *t =  new TreeNode(0);
            all[1].push_back(t);

            for(int i=3; i <= N; i +=2) {
                for(int j = 1; j <= i - 2; j++) {
                    for(auto& a: all[j]) {
                        for(auto& b: all[i-1-j]) {
                            TreeNode* x = new TreeNode(0);
                            x->left = a;
                            x->right = b;

                            all[i].push_back(x);
                        }
                    }
                }
            }

            return all[N];
        }
};
