#include <iostream>


using namespace std;


class Solution {
  int arr[26];
public:
    Solution() {
      for (int i = 0; i < 26; i++) arr[i] = 5 * i;
    };

    int getHash(string s) {
      int hash = 0;
      int n = s.length();
      int i = 0;
      for (char c : s) {
        int a = (n - i) * arr[c - 'a'];
        i += 1;
        hash += a;
      }
      return hash;
    };

    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (n < m) return -1;

        int nHash = this->getHash(needle);
        int hHash = this->getHash(haystack.substr(0, m));

        for (int i = 0; i < n - m; i++) {
            if (nHash == hHash && needle == haystack.substr(i, m)) return i;
            hHash = this->getHash(haystack.substr(i + 1, m));
        }

        hHash = this->getHash(haystack.substr(n - m, m));
        if (nHash == hHash && needle == haystack.substr(n - m, m)) return n - m;
        return -1;
    }
};


int main() {
    Solution solution;
    int index = solution.strStr("aaaabbbababb", "baa");
    return 0;
}