#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        priority_queue<pair<int, int>> maxHeap;
        vector<string> ans(n);

        for (int i = 0; i < n; i++) {
            maxHeap.push({score[i], i});
        }

        int rank = 1;

        while(!maxHeap.empty()) {
            auto [score, i] = maxHeap.top();
            maxHeap.pop();

            switch (rank) {
                case 1:
                    ans[i] = "Gold Medal";
                    break; 
                case 2:
                    ans[i] = "Silver Medal";
                    break;
                case 3:
                    ans[i] = "Bronze Medal";
                    break;
                default:
                    ans[i] = to_string(rank);
            }
            rank++;
        }

        return ans;
    }
};