#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int prev = 0, current = 0;
        
        for (int i = 1; i < n; i++) {
            if (colors[i - 1] == colors[i]) {
                current = prev + min(neededTime[i - 1], neededTime[i]);
                neededTime[i] = max(neededTime[i - 1], neededTime[i]);
                prev = current;
            }
        }

        return prev;
    }
};
