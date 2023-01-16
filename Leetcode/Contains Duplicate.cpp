//https://leetcode.com/problems/contains-duplicate/submissions/879263591/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (auto val: nums){
            mp[val]++;
            if (mp[val]==2)return true;
        }
        return false;
    }
};
