#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

static int _ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		vector<vector<int>> map(N + 1);
		unordered_set<int> s1, s2;
		vector<int> q1, q2;
		for (auto &p : dislikes) {
			map[p[0]].push_back(p[1]);
		}
		for (int k = 1; k < N; k++) {
			if (map[k].empty()) continue;
			s1.clear(), s2.clear();
			s1.insert(k);
			q1.push_back(k);
			while (!q1.empty()) {
				q2.clear();
				for (int i : q1) {
					for (int j : map[i]) {
						if (s1.count(j) > 0) return false;
						if (s2.count(j) == 0) {
							s2.insert(j);
							q2.push_back(j);
						}
					}
					map[i].clear();
				}
				swap(s1, s2);
				swap(q1, q2);
			}
		}
		return true;
	}
};

int main(int argc, const char *argv[])
{
    vector<vector<int>> dislikes{{1, 2}, {8, 2}, };
    Solution s;
    bool ok = s.possibleBipartition(2, dislikes);
    cout << ok << endl;
}
