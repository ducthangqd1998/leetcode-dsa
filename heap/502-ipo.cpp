#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int ans = w;
        int n = capital.size();
        vector<pair<int, int>> arr;
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < n; i++)
            arr.emplace_back(capital[i], profits[i]);
        
        sort(arr.begin(), arr.end(), [](const auto &a, const auto &b) {
           return a.first < b.first; 
        });

        int i = 0;

        while (k--) {
            while (i < n && w >= arr[i].first) {
                maxHeap.push({arr[i].second, arr[i].first});
                i++;
            }

            if (maxHeap.empty()) {
                break;
            }

            int p = maxHeap.top().first;
            int c = maxHeap.top().second;
            ans += p;
            maxHeap.pop();
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> profits = {1, 2, 3};
    vector<int> capital = {1, 1, 2};
    int k = 1;
    int w = 2;
    cout << solution.findMaximizedCapital(k, w, profits, capital) << "\n";
    return 0;
}