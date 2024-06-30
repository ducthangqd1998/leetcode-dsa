#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int count = 0;

        for (int i = 0; i < m; i++)
            count += matrix[i][0];
        for (int j = 1; j < n; j++)
            count += matrix[0][j];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j]) {
                    matrix[i][j] +=
                        min(matrix[i - 1][j - 1],
                            min(matrix[i][j - 1], matrix[i - 1][j]));
                }
                count += matrix[i][j];
            }
        }

        return count;
    }
};