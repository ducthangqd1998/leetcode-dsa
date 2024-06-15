#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void heapifyUp(vector<int> &arr, int index)
{
    while (index > 0)
    {
        int parent = (index - 1) / 2;
        if (arr[index] < arr[parent])
        {
            swap(arr[index], arr[parent]);
            index = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(vector<int> &arr, int n, int index)
{
    while (true)
    {
        int smallest = index;
        int left = index * 2 + 1;
        int right = index * 2 + 2;

        if (left < n and arr[left] < arr[smallest])
            smallest = left;
        if (right < n and arr[right] < arr[smallest])
            smallest = right;
        if (smallest != index)
        {
            swap(arr[index], arr[smallest]);
            index = smallest;
        }
        else
            break;
    }
}

void heapify(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDown(arr, n, i);
}

void heapPush(vector<int> &arr, int x) {
    arr.push_back(x);
    heapifyUp(arr, arr.size() - 1);
}

int heapPop(vector<int> &arr) {
    swap(arr[0], arr[arr.size() - 1]);
   
    int popped_value = arr.back();
    arr.pop_back();

    heapifyDown(arr, arr.size(), 0);
    return popped_value;
}

void heapSort(vector<int> &arr) {
    int n = arr.size();
    for (int i = n /  2 - 1; i >= 0; i--) 
        heapifyDown(arr, n, i);
    
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapifyDown(arr, i, 0);
    }
}

int main()
{
    vector<int> arr = {6, 15, 5, 9, 13, 4};
    heapify(arr);
    heapSort(arr);
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "\n";
    return 0;
}