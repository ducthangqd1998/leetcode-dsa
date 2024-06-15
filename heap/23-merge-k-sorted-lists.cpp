#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;

        auto cmp = [](const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

        for (auto node : lists)
        {
            if (node != nullptr)
            {
                pq.push(node);
            }
        }

        ListNode ans(0);
        ListNode *current = &ans;

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            current->next = node;
            current = node;
            if (node->next != nullptr)
            {
                pq.push(node->next);
            }
        }

        return ans.next;
    }
};
