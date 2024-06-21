#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string ans;

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            if (ans.empty() || ans.back() != top.second) {
                int count = min(top.first, 2);
                ans += string(count, top.second);
                top.first -= count;
                if (top.first > 0)
                    pq.push(top);
            } else {
                if (!pq.empty()) {
                    auto next = pq.top();
                    pq.pop();

                    ans += next.second;
                    next.first--;

                    pq.push(top);
                    if (next.first > 0)
                        pq.push(next);
                }
            }
        }
        return ans;
    }
};;
