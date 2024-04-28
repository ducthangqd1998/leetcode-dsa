#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> c;
        for (auto s1 : words) {
            for (auto s2 : words) {
                if (s1 != s2 && s2.find(s1, 0)!=string::npos) {
                    c.push_back(s1);
                    break;
                } 
            }
        }
        return c;
    }
};

int maii() {
    Solution solution;
    vector<string> words = {"mass", "as", "hero", "superhero"};
    solution.stringMatching(words);
    return 0;
}