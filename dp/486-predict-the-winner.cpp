#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int max_score(vector<vector<int>> &dp, vector<int> &sum, int l, int r) {
        if(dp[l][r] != 0)
            return dp[l][r];
    
        int s = sum[r] - sum[l - 1];
        
        if (l == r) {
            dp[l][r] = s;
        }
        else {
            dp[l][r] = s - min(max_score(dp, sum, l + 1, r), max_score(dp, sum, l, r - 1));
        }

        return dp[l][r];
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        vector<int> sum(n + 1, 0);

        for (int i = 1; i <= n ; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }

        int score = max_score(dp, sum, 1, n);
        return score >= sum[n] - score;
    }
};