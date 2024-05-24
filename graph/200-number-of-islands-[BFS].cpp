#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    void bfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (auto d : directions) {
                int newX = x + d[0];
                int newY = y + d[1];
                if (newX < 0 || newY < 0 || newX >= n || newY >= m ||
                    grid[newX][newY] != '1')
                    continue;
                q.push({newX, newY});
                grid[newX][newY] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    bfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }
};