#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        priority_queue<pair<int, int>> maxHeap;
        vector<int> result;
        
        for (int num : nums) {
            frequencyMap[num]++;
        }
        
        for (auto entry : frequencyMap) {
            maxHeap.push({entry.second, entry.first});
        }

        while (k--) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
    }
};