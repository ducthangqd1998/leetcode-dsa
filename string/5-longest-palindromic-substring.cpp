#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        
        int n = s.size();
        int start = 0, maxLength = 0;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLength) {
                    start = left;
                    maxLength = right - left + 1;
                }
                --left;
                ++right;
            }
        };
        
        for (int i = 0; i < n; ++i) {
            expand(i, i);
            expand(i, i + 1);
        }

        return s.substr(start, maxLength);
    };
};

int main() {
    Solution solution;
    solution.longestPalindrome("ThangMai");
    return 0;
}