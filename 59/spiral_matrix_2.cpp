/*
 *Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */

#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> > result(n, vector<int>(n, 0));

            int v = 0;
            for(int i = 0; i < n; i++) {
                result[0][i] = ++v;
            }

            int len = n;
            int c = n - 1;
            int r = 0;
            int flag = 1;
            while (--len) {
                int ec = c - flag * len; 
                int er = r + flag * len;
                int i = flag * len;
                int cv = v + len;
                int rv = cv + len;
                for(; i != 0; i -= flag) {
                    result[r+i][c] = cv--;
                    result[er][c-i] = rv--;
                }
                r = er;
                c = ec;
                v = v + 2 * len;
                flag = -flag;
            }

            return result;
        }
};
