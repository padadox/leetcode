/*
   Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

   Example 1:
        Input: "2-1-1"
        Output: [0, 2]
        Explanation: 
        ((2-1)-1) = 0 
        (2-(1-1)) = 2

   Example 2:
        Input: "2*3-4*5"
        Output: [-34, -14, -10, -10, 10]
        Explanation: 
        (2*(3-(4*5))) = -34 
        ((2*3)-(4*5)) = -14 
        ((2*(3-4))*5) = -10 
        (2*((3-4)*5)) = -10 
        (((2*3)-4)*5) = 10
 * */

/*
 * Dynamic Programming
 * */

#include <cstdlib>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int myplus(int a, int b) {
    return a + b;
}

int myminus(int a, int b) {
    return a - b;
}

int mymultiplies(int a, int b) {
    return a * b;
}

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> numbers;
        vector<int(*)(int, int)> ops;
        for(size_t i = 0; i < input.size(); ++i) {
            int a = atoi(&input[i]);
            numbers.push_back(a);

            for(; input[i] >= '0' && input[i] <= '9'; i++);

            if(i >= input.size()) {
                break;
            }

            if(input[i] == '+') {
                ops.push_back(myplus);
            }
            else if(input[i] == '-') {
                ops.push_back(myminus);
            }
            else {
                ops.push_back(mymultiplies);
            }
        }

        vector<vector<vector<int> > > results;
        results.resize(numbers.size()); // results of len 1 to n
        for(size_t i = 0; i < results.size(); i++) {
            results[i].resize(numbers.size() - i);
        }


        for(size_t i = 0; i < numbers.size(); i++) {
            results[0][i].push_back(numbers[i]);
        }

        for(size_t i = 1; i < results.size(); i++) {
            for(size_t j = 0; j < results[i].size(); j++) {
                for(size_t k = j; k < j + i; k++) {
                    for(size_t s = 0; s < results[k-j][j].size(); s++) {
                        for(size_t t = 0; t < results[i-k+j-1][k+1].size(); t++) {
                            int a = results[k-j][j][s];
                            int b = results[i-k+j-1][k+1][t];
                            results[i][j].push_back(ops[k](a, b));
                        }
                    }
                }
            }
        }
        return results[results.size()-1][0];
    }

};


