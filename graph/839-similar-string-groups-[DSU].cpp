#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class DSU
{
    vector<int> parent;
    vector<int> rank;
    int count;

public:
    DSU(int n) : count(n), rank(n, 0), parent(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    };

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        int p = find(parent[x]);
        parent[x] = p;
        return p;
    };

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
            count--;
        }
    };

    int getCount()
    {
        return this->count;
    }
};

class Solution
{
public:
    int numSimilarGroups(vector<string> &strs)
    {
        int n = strs.size();
        DSU *uf = new DSU(n);

        auto checkSimilar = [&](string x, string y)
        {
            int diff = 0;
            for (int i = 0; i < x.length(); i++)
            {
                if (x[i] != y[i])
                    diff++;
                if (diff > 2)
                    return false;
            }
            return diff == 2 || diff == 0;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (checkSimilar(strs[i], strs[j]))
                {
                    uf->unite(i, j);
                }
            }
        }
        return uf->getCount();
    }
};