#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class TrieNode
{
public:
    std::map<char, TrieNode *> child;
    bool finished;
    TrieNode() : finished(false) {}
};

class Solution
{
public:
    TrieNode *root;
    Solution() : root(new TrieNode()) {}

    string longestWord(vector<string> &words)
    {
        for (auto s : words)
            this->insert(s);
        string w = "";
        for (auto s : words)
        {
            if (this->check(s))
            {
                if (s.length() > w.length())
                    w = s;
                if (s.length() == w.length())
                    w = min(s, w);
            }
        }
        return w;
    }

    void insert(string s)
    {
        TrieNode *current = this->root;
        for (char c : s)
        {
            if (current->child.find(c) == current->child.end())
                current->child[c] = new TrieNode();
            current = current->child[c];
        }
        current->finished = true;
    }

    bool check(string s)
    {
        TrieNode *current = this->root;
        for (char c : s)
        {
            if (!current->child[c]->finished)
                return false;
            current = current->child[c];
        }
        return current->finished;
    }
};

int main()
{
    vector<string> words = {"yo", "ew", "fc", "zrc", "yodn", "fcm", "qm", "qmo", "fcmz", "z", "ewq", "yod", "ewqz", "y"};
    Solution solution;
    string w = solution.longestWord(words);
    return 0;
}