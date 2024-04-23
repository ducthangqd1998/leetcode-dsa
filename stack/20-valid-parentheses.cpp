#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
  stack<char> stack;

    bool isValid(string s) {
        for (char c : s) {
            if (c == '{' || c == '(' || c == '[') stack.push(c);
            else if (c == '}' && !stack.empty() && stack.top() == '{') stack.pop();
            else if (c == ']' && !stack.empty() && stack.top() == '[') stack.pop();
            else if (c == ')' && !stack.empty() && stack.top() == '(') stack.pop();
            else return false;
        }
        return stack.empty();
  }
};


int main() {
  Solution s;
  bool valid = s.isValid("]");
  return 0;
}
