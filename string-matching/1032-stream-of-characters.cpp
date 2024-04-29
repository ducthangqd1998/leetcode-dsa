#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class TrieNode
{
public:
    map<char, TrieNode *> child;
    bool finished = false;
};

class StreamChecker
{
public:
    TrieNode* root;
    string str = "";
    // StreamChecker() : root(new TrieNode()) {}
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (auto s : words)
            this->insert(s);
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
        for (char c : s) {
            if (current->child.find(c) == current->child.end()) 
                return false;
            current = current->child[c];
        }
        return current->finished;
    }

    bool query(char letter)
    {
        this->str += letter;
        int n = this->str.length();
        for (int i = 0; i < n; i++) {
            if (this->check(this->str.substr(i, n - i))) {
                this->str = "";
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<string> words = {"cd", "f", "kl"};
    StreamChecker streamChecker(words);
    streamChecker.query('a'); // return False
    streamChecker.query('b'); // return False
    streamChecker.query('c'); // return False
    streamChecker.query('d'); // return True, because 'cd' is in the wordlist
    streamChecker.query('e'); // return False
    streamChecker.query('f'); // return True, because 'f' is in the wordlist
    streamChecker.query('g'); // return False
    streamChecker.query('h'); // return False
    streamChecker.query('i'); // return False
    streamChecker.query('j'); // return False
    streamChecker.query('k'); // return False
    streamChecker.query('l'); // return True, because 'l' is in the wordlist
    return 0;
}