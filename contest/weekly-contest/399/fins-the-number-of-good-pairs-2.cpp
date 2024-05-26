#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        unordered_map<long long, int> m;

        for (int num : nums2)
        {
            m[num * k]++;
        }

        long long count = 0;

        for (int num : nums1)
        {
            for (int i = 1; i <= sqrt(num); ++i)
            {
                if (num % i == 0)
                {
                    count += m[i];
                    if (num / i != i)
                    {
                        count += m[num / i];
                    }
                }
            }
        }

        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 3, 4};
    int a = solution.numberOfPairs(nums1, nums1, 1);
    return 0;
}
