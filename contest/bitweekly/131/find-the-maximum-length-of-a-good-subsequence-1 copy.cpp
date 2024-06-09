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
        std::vector<int> dp(k + 1, 0);

        for (int i = 0; i < n; ++i)
        {
            dp[0] = std::max(dp[0], 1);
            for (int j = k; j > 0; --j)
            {
                if (nums[i] == nums[i - j])
                {
                    dp[j] = std::max(dp[j], dp[j] + 1);
                }
                else
                {
                    dp[j] = dp[j - 1];
                }
            }
        }
        return dp[k];
    }
};

int main()
{
    vector<int> skills = {1, 2, 3, 4, 5, 1};
    int k = 0;

    Solution solution;
    int currentWinner = solution.maximumLength(skills, k);
    cout << currentWinner;
    return 0;
}