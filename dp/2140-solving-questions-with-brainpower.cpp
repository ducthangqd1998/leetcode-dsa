#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);;
        for (int i = n - 1; i >=0; i--) {
            int nextQuestion = min(n, questions[i][1] + i + 1);
            dp[i] = max(dp[i + 1], questions[i][0] + dp[nextQuestion]);
        }
        return dp[0];
    }
};