#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& graph, int node, vector<int>& currentPath,
             vector<vector<int>>& paths) {
        currentPath.push_back(node);
        if (node == graph.size() - 1)
            paths.push_back(currentPath);
        else
            for (int d : graph[node])
                dfs(graph, d, currentPath, paths);
        currentPath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited;
        vector<int> currentPath;
        vector<vector<int>> paths;
        dfs(graph, 0, currentPath, paths);
        return paths;
    }
};

int main() {
    Solution solution;
    return 0;
}