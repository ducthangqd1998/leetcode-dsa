#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <numeric>

using namespace std;

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> arr;

        for (int i = lo; i <= hi; i++) {
            int num = i;
            int count = 0;

            while(num > 1) {
                if (num % 2 == 0)
                    num /= 2;
                else 
                    num = 3 * num + 1;
                count++;
            }

            arr.push_back({count, i});
        }
        
        sort(arr.begin(), arr.end());
        return arr[k - 1].second;
    }
};