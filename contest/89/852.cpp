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


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int low = 1;
        int high = A.size() - 2;
        int middle = 0;

        while(low <= high) {
            middle = (low + high) >> 1;

            if(A[middle] > A[middle-1] && A[middle+1] < A[middle]) {
                break;
            }

            if(A[middle] < A[middle+1]) {
                low = middle + 1;
            }
            else {
                high = middle - 1;
            }
        }

        return middle;
        
    }
};

int main(int argc, const char *argv[])
{
    vector<int> A{24,69,100,99,79,78,67,36,26,19};

    cout << Solution().peakIndexInMountainArray(A);
    
    return 0;
}
