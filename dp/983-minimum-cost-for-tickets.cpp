#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        if (n == 1) 
            return *min_element(costs.begin(), costs.end());
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = costs[0];

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + costs[0];

            for (int j = i - 1; j >= 0 && days[i - 1] - days[j] < 7; j--) {
                dp[i] = min(dp[i], (j > 0 ? dp[j] : 0) + costs[1]);
            }

            for (int j = i - 1; j >= 0 && days[i - 1] - days[j] < 30; j--) {
                dp[i] = min(dp[i], (j > 0 ? dp[j] : 0) + costs[2]);
            }
        }

        return dp[n];
    }
};