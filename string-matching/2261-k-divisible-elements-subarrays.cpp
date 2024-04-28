#include <iostream>
#include <stdio.h>
#include <map>
#include <set>

using namespace std;

long long mod = 1e11 + 7;

class Solution
{
public:
    int countDistinct(vector<int> &nums, int k, int p)
    {
        set<long long> c;
        for (int i = 0; i < nums.size(); i++)
        {
            long long hash = 0;
            int check = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if (!(nums[j] % p))
                    check += 1;
                if (check > k)
                    break;
                hash = (hash * 201 + nums[j]) % mod;
                c.insert(hash);
            }
        }
        return c.size();
    }
};

int main()
{
    Solution solution;
    vector<int> n = {2, 3, 3, 2, 2};
    solution.countDistinct(n, 2, 2);
    return 1;
}
