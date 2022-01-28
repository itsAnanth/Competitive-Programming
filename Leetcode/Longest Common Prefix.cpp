// https://leetcode.com/problems/longest-common-prefix

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (!len) return "";
        
        sort(strs.begin(), strs.end());
        string ans, L = strs[0], H = strs[len - 1];
        int i = -1;
        FOR(i, 0, H.size(), 1) {
            if (L[i] == H[i])
                ans += L[i];
            else break;
        }
        return ans;
    }
};
