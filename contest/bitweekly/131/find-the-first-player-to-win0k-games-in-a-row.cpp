#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findWinningPlayer(vector<int> &skills, int k)
    {
        int n = skills.size();
        queue<int> q;
        for (int i = 0; i < n; i++)
            q.push(i);

        int currentWinner = q.front();
        int count = 0;
        q.pop();
        while (count < k)
        {
            int current = q.front();
            q.pop();
            if (skills[current] > skills[currentWinner])
            {
                q.push(currentWinner);
                currentWinner = current;
                count = 1;
            }
            else
            {
                count++;
                q.push(current);
            }
            if (count >= k || count > n) {
                return currentWinner;
            }
        }
        return currentWinner;
    }
};

int main()
{
    vector<int> skills = {2, 5, 4};
    int k = 3;

    Solution solution;
    int currentWinner = solution.findWinningPlayer(skills, k);
    cout << currentWinner;
    return 0;
}