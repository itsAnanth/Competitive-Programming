// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2, 0);
        int l = 0, h = numbers.size() - 1;
        while (l < h) {
            int curr = numbers[l] + numbers[h];
            if (curr == target) {
                ans[0] = l + 1;
                ans[1] = h + 1;
                break;
            } else if (curr < target)
                l++;
            else if (curr > target)
                h--;
        }
        return ans;
        
    }
};