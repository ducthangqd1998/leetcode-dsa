#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    bool ans = true;


    void dfs(vector<vector<int>> &graph, vector<int> &colors, vector<int> &visited, int i, int color) {
        if (colors[i] == -1)
            colors[i] = color;
        else if (colors[i] != color)
            ans = false;
        if (visited[i])
            return;
        else
            visited[i] = 1;
        for (int node: graph[i])
            dfs(graph, colors, visited, node, !color);
    }

    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.empty())
            return true;
        int n = graph.size();
        vector<int> colors(n, -1);
        vector<int> vistied(n, 0);

        for (int i = 0; i < n; ++i) {
            int color = 0;
            if (colors[i] != -1)
                color = colors[i];
            
            dfs(graph, colors, vistied, i, color);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> graph = {{},{2,4,6},{1,4,8,9},{7,8},{1,2,8,9},{6,9},{1,5,7,8,9},{3,6,9},{2,3,4,6,9},{2,4,5,6,7,8}};
    solution.isBipartite(graph);
    return 0;
}