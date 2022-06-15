#include <bits/stdc++.h>

int binSearch(int, std::vector<int>);

int main() {
    std::vector<int>nums = { 10, 5, 4, 3, 2, 1 };
    std::sort(nums.begin(), nums.end());
    
    int idx = binSearch(5, nums);
    
    std::cout << idx;
    return 0;
}

int binSearch(int num, std::vector<int> arr) {
    int L = 0, H = arr.size() - 1, idx = -1;
    
    while (L <= H) {
        int mid = (L + H) / 2, curr = arr[mid];
        
        if (curr == num) {
            idx = mid;
            break;
        } else if (curr < num) L++;
        else H--;
    }
    
    return idx;
}
