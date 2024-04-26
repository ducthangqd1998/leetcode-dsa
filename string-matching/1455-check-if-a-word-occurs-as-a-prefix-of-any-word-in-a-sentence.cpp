#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        vector<string> arr;
        int first = 0;
        int n = searchWord.length();

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == ' ')
            {
                arr.push_back(sentence.substr(first, i - first));
                first = i + 1;
            }
        }

        arr.push_back(sentence.substr(first, sentence.length() - first));

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i].length() >= searchWord.length() && arr[i].substr(0, n) == searchWord)
                return i + 1;
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    solution.isPrefixOfWord("love errichto jonathan dumb", "dumb");
    return 0;
}