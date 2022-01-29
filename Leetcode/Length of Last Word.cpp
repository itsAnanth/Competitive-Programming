// https://leetcode.com/problems/length-of-last-word

#define FOR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1, len = 0, g = false;
        FOR(i, s.size() - 1, -1, -1) {
            if (s[i] != ' ') {
                len++; g = true;
            } else if (s[i] == ' ' && g) break;
        }
        return len;
    }
};
