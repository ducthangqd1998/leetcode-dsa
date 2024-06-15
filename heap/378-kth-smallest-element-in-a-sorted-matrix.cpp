#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int result = 0;
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        for (int i = 0; i < min(n, k); i++) {
            minHeap.push({matrix[i][0], {i, 0}});
        }

        while (k--) {
            auto smallest = minHeap.top();
            minHeap.pop();
            result = smallest.first;
            int row = smallest.second.first;
            int col = smallest.second.second;

            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], {row, col + 1}});
            }
        }

        return result;
    }
};
