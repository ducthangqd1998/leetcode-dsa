#include <iostream>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int fullBottles = 0;
        int emptyBottles = 0;

        while(numBottles >= numExchange) {
            fullBottles = numBottles / numExchange;
            emptyBottles = numBottles - fullBottles * numExchange;
            numBottles = fullBottles + emptyBottles;

            ans += fullBottles;
        };

        return ans;
    }
};