#include <stdio.h>
#include <map>

using namespace std;

class TrieNode
{
public:
    std::map<char, TrieNode *> children;
    bool finished;
    TrieNode() : finished(false) {}
};

class Trie
{
    TrieNode *root;

public:
    Trie() : root(new TrieNode()) {}

    void insert(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
                current->children[c] = new TrieNode();
            current = current->children[c];
        }
        current->finished = true;
    }

    bool search(string word)
    {
        TrieNode *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
                return false;
            current = current->children[c];
        }
        return current->finished;
    }

    bool startsWith(string prefix)
    {
        TrieNode *current = root;
        for (char c : prefix)
        {
            if (current->children.find(c) == current->children.end())
                return false;
            current = current->children[c];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app"); // return True
    return 0;
}