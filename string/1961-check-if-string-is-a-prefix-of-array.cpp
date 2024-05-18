#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string word = "";
        for (int i = 0; i < words.size(); i++) {
            word += words[i];
            if (word == s)
                return true;
        }
        return false;
    }
};
