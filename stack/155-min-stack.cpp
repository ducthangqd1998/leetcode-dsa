#include <iostream>

using namespace std;


class Node {
public:
    int num;
    Node* node; 

    Node (int n) {
        this->num = n;
        this->node = NULL;
    }
};

class MinStack {
public:
    Node* root;
    MinStack() {
        root = NULL;
    }
    
    void push(int val) {
        Node* temp = new Node(val);
        temp->num = val;
        temp->node = this->root;
        this->root = temp;
    }
    
    void pop() {
        Node* temp = this->root->node;
        root = temp;
    }
    
    int top() {
        return this->root->num;
    }
    
    int getMin() {
        Node* current = this->root;
        int min = current->num;
        while (current != NULL) {
            if(current->num < min) min = current->num;
            current = current->node;
        }
        return min;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin();
    return 0;
}