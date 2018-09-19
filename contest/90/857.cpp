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

struct CmpQuality{
    vector<int> *quality;
    CmpQuality(vector<int> & quality) {
        this->quality = &quality;
    }

    bool operator()(int i, int j) {
        return (*quality)[i] < (*quality)[j];
    }
};

struct CmpAveWage{
    vector<double> *ave_wage;
    CmpAveWage(vector<double> & ave_wage) {
        this->ave_wage = &ave_wage;
    }

    bool operator()(int i, int j) {
        return (*ave_wage)[i] > (*ave_wage)[j];
    }

};

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        vector<int> idx_quality;
        vector<double> ave_wage;
        vector<int> idx_ave_wage;

        ave_wage.resize(quality.size());
        for(size_t i = 0; i < quality.size(); ++i) {
            ave_wage[i] = 1. * wage[i] / quality[i];
        }

        idx_quality.resize(quality.size());
        for(size_t i = 0; i < idx_quality.size(); ++i) {
            idx_quality[i] = i;
        }

        idx_ave_wage = idx_quality;

        sort(idx_ave_wage.begin(), idx_ave_wage.end(), CmpAveWage(ave_wage));
        nth_element(idx_quality.begin(), idx_quality.begin() + (K-1), idx_quality.end(), CmpQuality(quality));
        sort(idx_quality.begin() + K, idx_quality.end(), CmpQuality(quality));

        vector<bool> flag(quality.size(), false);
        int sum_quality = 0;
        for(int i = 0; i < K-1; i++) {
            sum_quality += quality[idx_quality[i]];
            flag[idx_quality[i]] = true;
        }

        int last = K - 2;

        double cost = std::numeric_limits<double>::max();
        for(size_t i = 0; i < idx_ave_wage.size() - K + 1; ++i) {
            size_t idx = idx_ave_wage[i];

            double cur_cost = 0.;

            if(!flag[idx]) {
                sum_quality += quality[idx];
                flag[idx] = true;
            }
            else {
                while(flag[idx_quality[++last]]);
                sum_quality += quality[idx_quality[last]];
                flag[idx_quality[last]] = true;
            }

            cur_cost = ave_wage[idx] * sum_quality;
            if(cur_cost < cost) {
                cost = cur_cost;
            }

            sum_quality -= quality[idx];
        }

        return cost;
    }

};

int main(int argc, const char *argv[])
{
    vector<int> A{3, 1, 10, 10, 1};
    vector<int> B{4, 8, 2, 2, 7};

    cout << Solution().mincostToHireWorkers(A, B, 3);

    return 0;
}
