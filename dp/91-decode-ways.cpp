#include <iostream>
#include <vector>

class Solution {
public:
    int numDecodings(const std::string& s) {
        if (s.empty() || s[0] == '0')
            return 0;

        int n = s.size();
        int dp1 = 1, dp2 = 1, dp = 0;

        for (int i = 2; i <= n; ++i) {
            dp = 0;
            int one = ctoi(s[i - 1]);
            int two = ctoi(s[i - 2]) * 10 + one;

            if (one >= 1 && one <= 9) {
                dp += dp1;
            }
            if (two >= 10 && two <= 26) {
                dp += dp2;
            }

            dp2 = dp1;
            dp1 = dp;
        }

        return dp1;
    }

private:
    int ctoi(char c) { return c - '0'; }
};

int main() {
    Solution solution;
    std::string s = "226";
    int result = solution.numDecodings(s);
    std::cout << "Number of decodings: " << result << std::endl;
    return 0;
}