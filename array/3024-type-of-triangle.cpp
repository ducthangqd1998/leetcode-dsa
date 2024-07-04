#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <numeric>

using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int max = *max_element(nums.begin(), nums.end());
        if (max >= sum - max) return "none";

        set<int> triagle(nums.begin(), nums.end());
        switch (triagle.size()) {
            case 1:
                return "equilateral";
            case 2:
                return "isosceles";
            default:
                return "scalene";
        }
    }
};