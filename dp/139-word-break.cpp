#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(const string& s, const vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.length();
        int max_len = 0;
        for (auto word : dict) {
            max_len = max(max_len, static_cast<int>(word.length()));
        }
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};