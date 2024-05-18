#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();
        auto expand = [&](int i, int j) {
            while (i >= 0 && j < n && s[i] == s[j]) {
                count += 1;
                --i;
                ++j;
            }
        };
        for (int i = 0; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return count;
    }
};