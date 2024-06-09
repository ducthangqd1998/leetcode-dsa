#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

class Solution
{
public:
    string clearDigits(string s)
    {
        vector<char> temp(s.begin(), s.end());
        int i = 0;
        while (i < temp.size())
        {
            if (isdigit(temp[i]))
            {
                temp.erase(temp.begin() + i);
                for (int j = i - 1; j >= 0; j--)
                {
                    if (!isdigit(temp[j]))
                    {
                        temp.erase(temp.begin() + j);
                        break;
                    }
                }
                i = 0;
            }
            else
                i++;
        }
        return string(temp.begin(), temp.end());
    }
};

int main()
{
    string s = "abc";
    Solution solution;
    string a = solution.clearDigits(s);
    cout << a;
    return 0;
}