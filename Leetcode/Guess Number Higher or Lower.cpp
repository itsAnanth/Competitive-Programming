// https://leetcode.com/problems/guess-number-higher-or-lower
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, h = n;
        while (true) {
            int mid = (h - l) / 2 + l,
                res = guess(mid);
            if (res == 0)
                return mid;
            else if (res > 0)
                l = mid + 1;
            else 
                h = mid - 1;
        }
    }
};
