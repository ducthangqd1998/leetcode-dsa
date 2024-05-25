#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    int bfs(vector<vector<int>> &grid, int i, int j, int m, int n) {
        int area = 0;
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            area++;
            grid[x][y] = 0;

            for (auto d: directions) {
                int newX = x + d[0];
                int newY = y + d[1];
                cout << newX << "\n";
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                    q.push({newX, newY});
                    grid[newX][newY] = 0;
                }
            }
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int area = bfs(grid, i, j, m, n);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;   
    }
};

int main() {
    vector<vector<int>>grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};

    Solution solution;
    solution.maxAreaOfIsland(grid);
    return 0;
}