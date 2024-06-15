#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> maxHeap;

        for (auto point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            maxHeap.push({distance, point});

            if (maxHeap.size() > k)
                maxHeap.pop();
        }

        while (maxHeap.size()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return ans;
    }
};