#include <stdio.h>
#include <bits/stdc++.h>
#include <cmath>


using namespace std;


int binarySearch(int arr[], int l, int r, int x) {
    int mid = floor(l + r) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[mid] < x) {
        binarySearch(arr, mid, r, x);
    } else {
        binarySearch(arr, l, mid, x);
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 13, 13, 18, 36};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, 13);
    (result == -1)
        ? cout << "Element is not present in arr"
        : cout << "Element is present at index " << result;
    return 0;
}