#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char, int> m;
        priority_queue<pair<int, char>> maxHeap;
        for (auto c : s)
            m[c]++;

        for (auto& item : m) {
            maxHeap.push({item.second, item.first});
        }
        string ans;
        ans.reserve(s.size());
        while (!maxHeap.empty()) {
            auto [freq, item] = maxHeap.top();
            maxHeap.pop();
            ans.append(freq, item);
        }
        return ans;
    }
};