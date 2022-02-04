#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
 		int S = 0, i = 0, j = height.size() - 1;
        while (i < j) {
            S = max(S, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j]) 
                i++; 
            else 
                j--;
        }
        return S;
        // return (ri - li) * min(l, r);
    }
};