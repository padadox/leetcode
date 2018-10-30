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
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int ans = -1;
        int start = 0;
        int sum = 0;
        for(int i = 0; i < A.size(); ++i) {
            if(A[i] > 0) {
                sum += A[i];

                if(sum >= K) {
                    int cur_sum = 0;
                    int j = 0;
                    int max_j = 0;
                    int max_sum = 0;
                    for(j = i; j >= start; --j) {
                        cur_sum += A[j];
                        if(cur_sum >= K) {
                            break;
                        }

                        if(cur_sum > max_sum) {
                            max_sum = cur_sum;
                            max_j = j;
                        }
                    }

                    int cur_ans = i - j + 1;
                    if(ans == -1 || cur_ans < ans) {
                        ans = cur_ans;
                    }

                    start = max_j;
                    sum = max_sum;
                }
            }
            else {
                sum += A[i];
                if(sum <= 0) {
                    start = i + 1;
                    sum = 0;
                }
            }
        }
        
        return ans;
    }
};
*/

class Solution {
    public:
        int shortestSubarray(vector<int> A, int K) {
            int N = A.size(), res = N + 1;
            vector<int> B(N + 1, 0);
            for (int i = 0; i < N; i++) B[i + 1] = B[i] + A[i];
            deque<int> d;
            for (int i = 0; i < N + 1; i++) {
                while (d.size() > 0 && B[i] - B[d.front()] >= K)
                    res = min(res, i - d.front()), d.pop_front();
                while (d.size() > 0 && B[i] <= B[d.back()]) d.pop_back();
                d.push_back(i);
            }
            return res <= N ? res : -1;
        }
};

int main(int argc, const char *argv[])
{
    //vector<int> A {39353,64606,-23508,5678,-17612,40217,15351,-12613,-37037,64183,68965,-19778,-41764,-21512,17700,-23100,77370,64076,53385,30915,18025,17577,10658,77805,56466,-2947,29423,50001,31803,9888,71251,-6466,77254,-30515,2903,76974,-49661,-10089,66626,-7065,-46652,84755,-37843,-5067,67963,92475,15340,15212,54320,-5286};
    // {77370, 64076, 53385, 30915};
   // {39353,64606,-23508,5678,-17612,40217,15351,-12613,-37037,64183,68965,-19778,-41764,-21512,17700,-23100,77370,64076,53385,30915,18025,17577,10658,77805,56466,-2947,29423,50001,31803,9888,71251,-6466,77254,-30515,2903,76974,-49661,-10089,66626,-7065,-46652,84755,-37843,-5067,67963,92475,15340,15212,54320,-5286};
    //int K = 207007;

    vector<int> A{1, 2, 5};
    int K = 8;

    Solution s;
    cout << s.shortestSubarray(A, K) << endl;

    return 0;
}
