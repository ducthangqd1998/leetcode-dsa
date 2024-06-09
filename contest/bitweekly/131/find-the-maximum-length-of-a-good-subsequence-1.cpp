#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<vector<int>> dp(n, vector<int>(k + 1, 0));

        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                for (int p = 0; p < i; ++p)
                {
                    if (nums[p] == nums[i])
                    {
                        dp[i][j] = std::max(dp[i][j], dp[p][j] + 1);
                    }
                    else if (j > 0)
                    {
                        dp[i][j] = std::max(dp[i][j], dp[p][j - 1] + 1);
                    }
                }
            }
        }

        int maxLength = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= k; ++j)
            {
                maxLength = std::max(maxLength, dp[i][j]);
            }
        }

        return maxLength;
    }
};

int main()
{
    vector<int> skills = {1,2,3,4,5,1};
    int k = 0;

    Solution solution;
    int currentWinner = solution.maximumLength(skills, k);
    cout << currentWinner;
    return 0;
}