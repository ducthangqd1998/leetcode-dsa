#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {
        {0, 1}, {0, -1}, {-1, 0}, {1, 0},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid.empty() || grid[0][0] != 0 || grid[n-1][n-1] != 0) {
            return -1;
        }
        
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // mark as visited
        
        int distance = 1;
        
        while (!q.empty()) {
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                auto [x, y] = q.front();
                q.pop();
                
                if (x == n-1 && y == n-1) {
                    return distance;
                }
                
                for (const auto& dir : directions) {
                    int new_x = x + dir[0];
                    int new_y = y + dir[1];
                    
                    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && grid[new_x][new_y] == 0) {
                        q.push({new_x, new_y});
                        grid[new_x][new_y] = 1; // mark as visited
                    }
                }
            }
            ++distance;
        }
        
        return -1;
    }
};


int main() {
    vector<vector<int>> grid = {{0,1,1,0,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,1,1,0},{1,1,1,1,0}};
    Solution solution;
    solution.shortestPathBinaryMatrix(grid);
    return 0;
}

