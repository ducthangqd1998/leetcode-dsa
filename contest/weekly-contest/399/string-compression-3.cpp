#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    string compressedString(const string &word)
    {
        if (word.empty())
            return "";

        string compressed = "";
        int idx = 0;

        while (idx < word.size())
        {
            int count = 0;
            char prev = word[idx];
            while (word[idx] == prev && count < 9)
            {
                idx++;
                count++;
            }
            compressed += to_string(count) + prev;
        }

        return compressed;
    }
};
