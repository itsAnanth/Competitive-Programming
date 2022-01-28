// https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m;
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if (m.find(n) != m.end()) {
                v.push_back(i);
                v.push_back(m[n]);
                break;
            } else
                m[nums[i]] = i;
        }
        return v;
    }
};
