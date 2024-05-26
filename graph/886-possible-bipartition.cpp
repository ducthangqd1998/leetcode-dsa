#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n);
        vector<int> colors(n, -1);

        for (auto& pair : dislikes) {
            adj[pair[0] - 1].push_back(pair[1] - 1);
            adj[pair[1] - 1].push_back(pair[0] - 1);
        }

        function<bool(int, int)> dfs = [&](int node, int color) {
            colors[node] = color;
            for (int neighbor : adj[node]) {
                if (colors[neighbor] == -1) {
                    if (!dfs(neighbor, 1 - color))
                        return false;
                }
                else if (colors[neighbor] == color)
                    return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            if (colors[i] == -1)
                if (!dfs(i, 0))
                    return false;
        }
        return true;
    }
};