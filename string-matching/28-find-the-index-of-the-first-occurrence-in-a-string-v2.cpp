#include <iostream>


using namespace std;


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (n < m) return -1;

        for (int i = 0; i < n - m; i++) {
            if (needle == haystack.substr(i, m)) return i;
        }
        if (needle == haystack.substr(n - m, m)) return n - m;
        return -1;
    }
};


int main() {
    Solution solution;
    int index = solution.strStr("aaaabbbababb", "baa");
    return 0;
}