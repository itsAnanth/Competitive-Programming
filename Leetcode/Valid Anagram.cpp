//https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a = s.size(), b = t.size();

        if (a != b) return false;

        std::unordered_map<char, int> x, y;
        for (int i = 0; i < a; i++) {
            x[s[i]]++;
            y[t[i]]++;
        }

        return x == y;
    }
};
