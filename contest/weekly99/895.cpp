
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
