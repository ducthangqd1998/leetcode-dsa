#include <iostream>

using namespace std;

class Solution
{
public:
    int arr[26];
    Solution()
    {
        for (int i = 0; i < 26; i++)
            arr[i] = 2 * (i + 1);
    }

    int getHash(string s)
    {
        int hash = 0;
        for (char c : s)
        {
            hash += arr[c - 'a'];
        }
        return hash;
    }

    int checkPermutation(string s1, string s2)
    {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }

    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.length();
        int n2 = s2.length();

        int hash1 = this->getHash(s1);
        int hash2 = 0;

        for (int i = 0; i <= n2 - n1; i++)
        {
            hash2 = this->getHash(s2.substr(i, n1));

            if (hash1 == hash2 && this->checkPermutation(s1, s2.substr(i, n1)))
                return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    bool result = solution.checkInclusion("ab", "eidbaooo");
    return 0;
}