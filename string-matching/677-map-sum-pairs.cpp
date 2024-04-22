#include <stdio.h>
#include <map>

using namespace std;

class TrieNode {
public:
    std::map<char, TrieNode*> children;
    int count;

    TrieNode() : count(0) {}
};


class MapSum {
public:
    TrieNode *root;
    unordered_map<string, int> map;

    MapSum() : root(new TrieNode()) {}

    void insert(string key, int val) {
        TrieNode* current = root;
        int diff = val - map[key];
        for(char c : key) {
            if(current->children.find(c) == current->children.end()) {
                current->children[c] = new TrieNode();
            }
            current = current->children[c];
            current->count += diff;
            
        }
        map[key] = val;
    }


    int sum(string prefix) {
        TrieNode* current = root;
        for(char c : prefix) {
            if(current->children.find(c) == current->children.end()) {
                return 0;
            }
            current = current->children[c];
        }
        return current->count;
    }
};

int main() {
    MapSum mapSum;
    mapSum.insert("apple", 3);  
    mapSum.sum("ap");           // return 3 (apple = 3)
    mapSum.insert("app", 2);    
    mapSum.sum("ap");
}