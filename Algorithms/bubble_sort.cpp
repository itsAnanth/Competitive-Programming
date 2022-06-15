#include <bits/stdc++.h>

void bubbleSort(std::vector<int>);

int main() {
    std::vector<int>nums = { 10, 5, 4, 6, 3, 2, 1 };
    
    bubbleSort(nums);
    
    for (int i : nums) std::cout << i << ", ";
    
    return 0;
}

void bubbleSort(std::vector<int> arr) {
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        int swaps = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
            }
            if (!swaps) break;
        }
    }
}
