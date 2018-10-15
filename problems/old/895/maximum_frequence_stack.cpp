/*
Implement FreqStack, a class which simulates the operation of a stack-like data structure.

FreqStack has two functions:

push(int x), which pushes an integer x onto the stack.
pop(), which removes and returns the most frequent element in the stack.
If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 

Example 1:

Input: 
["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
Output: [null,null,null,null,null,null,null,5,7,5,4]
Explanation:
After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:

pop() -> returns 5, as 5 is the most frequent.
The stack becomes [5,7,5,7,4].

pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
The stack becomes [5,7,5,4].

pop() -> returns 5.
The stack becomes [5,7,4].

pop() -> returns 4.
The stack becomes [5,7].
 

Note:

Calls to FreqStack.push(int x) will be such that 0 <= x <= 10^9.
It is guaranteed that FreqStack.pop() won't be called if the stack has zero elements.
The total number of FreqStack.push calls will not exceed 10000 in a single test case.
The total number of FreqStack.pop calls will not exceed 10000 in a single test case.
The total number of FreqStack.push and FreqStack.pop calls will not exceed 150000 across all test cases.
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

typedef long long ll;
typedef pair<int,int> pii;
template<typename T> using min_queue=priority_queue<T,vector<T>,greater<T>>;

const ll MOD=1e9+7;

static auto __ = [] () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

struct Record {
    int val = 0;
    int freq = 0;
    int last = 0;
};

struct Cmp {
    bool operator()(Record& a, Record& b) {
        if(a.freq == b.freq) {
            return a.last < b.last;
        }

        return a.freq < b.freq;
    }

};

class FreqStack {
    private:
        int cnt = 0;
        map<int, vector<int>> all;
        priority_queue<Record, vector<Record>, Cmp> q;

    public:
            FreqStack() {

            }

            void push(int x) {
                auto &a = all[x];
                a.push_back(++cnt);
                Record r;
                r.val = x;
                r.freq = a.size();
                r.last = cnt;
                q.push(r);
            }

            int pop() {
                while(!q.empty()) {
                    Record r = q.top();
                    q.pop();

                    auto& a = all[r.val];
                    /*
                    if(a.empty()) {
                        continue;
                    }

                    if(r.last != a.back()) {
                        continue;
                    }

                    if(r.freq != a.size()) {
                        continue;
                    }

                    a.pop_back();

                    if(!a.empty()) {
                        r.freq--;
                        r.last = a.back();
                        q.push(r);
                    }
                    */

                    return r.val;
                }

                return 0;
            }
};


int main(int argc, const char *argv[])
{
    FreqStack s;
    s.push(5);
    s.push(7);
    s.push(5);
    s.push(7);
    s.push(4);
    s.push(5);
    s.push(4);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    
    return 0;
}
