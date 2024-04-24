#include <iostream>
#include <queue>

using namespace std;


class RecentCounter {
public:
    std::queue<int> queue;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int min = t - 3000;
        queue.push(t);
        while(queue.front() < min) queue.pop();
        return queue.size();
    }
};


int main() {
  RecentCounter counter;
  counter.ping(1);
  counter.ping(101);
  counter.ping(3001);
  counter.ping(3002);
  return 0;
}