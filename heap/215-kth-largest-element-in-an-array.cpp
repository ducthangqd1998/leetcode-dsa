#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void heapifyDown(vector<int> &arr, int n, int index)
{
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left < n and arr[left] > arr[largest])
        largest = left;
    if (right < n and arr[right] > arr[largest])
        largest = right;

    if (largest != index)
    {
        swap(arr[index], arr[largest]);
        heapifyDown(arr, n, largest);
    }
}

int heapPop(vector<int> &arr) {
    swap(arr[0], arr[arr.size() - 1]);
   
    int popped_value = arr.back();
    arr.pop_back();

    heapifyDown(arr, arr.size(), 0);
    return popped_value;
}

void heapify(vector<int> &arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapifyDown(arr, n, i);
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        heapify(nums);
        for (int i = 0; i < k - 1; i++)
            heapPop(nums);
        return heapPop(nums);
    }
};