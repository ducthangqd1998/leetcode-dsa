#include <stdio.h>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    int ans = 0;
    void dfs(int n, int headID, vector<vector<int>>& adj, vector<int>& informTime, int time) {
        if (!adj[headID].size())
            return;
        for (int i : adj[headID]) {
            dfs(n, i, adj, informTime, time + informTime[i]);
        }
        if (time > ans)
            ans = time;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager,
                     vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1)
                adj[manager[i]].push_back(i);
        }
        dfs(n, headID, adj, informTime, informTime[headID]);
        return ans;
    }
};

int main()
{
    int n = 7;
    int headID = 6;
    vector<int> manager = {1,2,3,4,5,6,-1};
    vector<int> informTime = {0,6,5,4,3,2,1};

    Solution solution;
    int num = solution.numOfMinutes(n, headID, manager, informTime);
    return num;
}