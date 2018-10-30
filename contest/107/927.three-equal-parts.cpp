/*
 * 问题描述
 * [963] Three Equal Parts
 *
 * https://leetcode.com/problems/three-equal-parts/description/
 *
 * algorithms
 * Hard (24.95%)
 * Total Accepted:    1.9K
 * Total Submissions: 7.2K
 * Testcase Example:  '[1,0,1,0,1]'
 *
 * Given an array A of 0s and 1s, divide the array into 3 non-empty parts such
 * that all of these parts represent the same binary value.
 * 
 * If it is possible, return any [i, j] with i+1 < j, such that:
 * 
 * 
 * A[0], A[1], ..., A[i] is the first part;
 * A[i+1], A[i+2], ..., A[j-1] is the second part, and
 * A[j], A[j+1], ..., A[A.length - 1] is the third part.
 * All three parts have equal binary value.
 * 
 * 
 * If it is not possible, return [-1, -1].
 * 
 * Note that the entire part is used when considering what binary value it
 * represents.  For example, [1,1,0] represents 6 in decimal, not 3.  Also,
 * leading zeros are allowed, so [0,1,1] and [1,1] represent the same
 * value.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,1,0,1]
 * Output: [0,3]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,0,1,1]
 * Output: [-1,-1]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 3 <= A.length <= 30000
 * A[i] == 0 or A[i] == 1
 * 
 * 
 * 
 * 
 * 
 * 
 */


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
 * 解决方案
 * 方法1:
 * DP.
 * 关键在于找到简单量(有效长度)。
 * 方法2：
 * 统计1的个数，每个部分1的个数应该相等，所以可以按1的个数找到边界。
 */

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> ans(2, -1);
        int n = A.size();

        int low = 1;
        int high = n / 3;
        
        while(low <= high) {
            int middle = (low + high) / 2;

            int i = 0;
            for(; i < n && 0 == A[i]; i++);
            if(i == n) {
                ans[0] = 0;
                ans[1] = 2;
                break;
            }

            int j = i + middle;
            for(; j < n && 0 == A[j]; j++);
            int k = j + middle;
            for(; k < n && 0 == A[k]; k++);

            if(k + middle > n) {
                high = middle - 1;
                continue;
            }
            else if(k + middle < n) {
                low = middle + 1;
                continue;
            }

            int m = 0;
            for(m = 0; m < middle; m++) {
                if(A[i+m] != A[j+m] || A[i+m] != A[k+m]) {
                    break;
                }
            }

            if(m >= middle) {
                ans[0] = i + middle - 1;
                ans[1] = j + middle;
            }

            break;
        }

        return ans;
    }
};


/*
 *
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
	    // Count no of 1's in the given array
        int countNumberOfOnes = 0;
        for(int c: A)
            if(c == 1)                  
                countNumberOfOnes++;
								
	    // If no 1 is found, that means we can return ans as {0, size-1}
        if(countNumberOfOnes == 0)      
            return {0, A.size()-1};
						
        // If no of 1's is not a multiple of 3, then we can never find a possible partition since
        // there will be atkeast one partition that will have different no of 1's and hence
        // different binary representation
        // For example,
        // Given :
        // 0000110  110  110 
        //       |  |    |
        //       i       j
        // Total no of ones = 6
        // 0000110         110      110
        //     |           |        |
        //     start       mid      end
        // Match starting from first 1, and putting 2 more pointers by skipping k 1's
        
        if(countNumberOfOnes % 3 != 0)            
            return {-1, -1};
						
        // find size of each partition
        int k = countNumberOfOnes/3;
        int i;
        
        // find the first 1 in the array
        for(i=0;i<A.size(); i++)
            if(A[i] == 1)
                break;
        int start = i;
        
        // find (k+1)th 1 in the array
        int count1 = 0;
        for(i=0;i<A.size(); i++)
        {
            if(A[i] == 1)
                count1++;
            if(count1 == k + 1)
                break;
        }
        int mid = i;
        
        //find (2*k +1)th 1 in the array
        count1= 0;
        for(i=0;i<A.size(); i++)
        {
            if(A[i] == 1)
                count1++;
            if(count1 == 2*k + 1)
                break;
        }
        int end = i;
        
        // Match all values till the end of the array
        while(end< A.size() && A[start] == A[mid] && A[mid] == A[end])
        {
            start++; mid++; end++;
        }
        
        // Return appropriate values if all the values have matched till the end
        if(end == A.size()) 
            return {start-1, mid};
        
        // otherwise, no such indices found
        return {-1, -1};
    }
};

*/
