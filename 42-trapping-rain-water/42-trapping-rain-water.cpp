class Solution {
public:
    int trap(vector<int> &heights) {
        int l = 0, r = heights.size() - 1, res = 0;
        int l_max = heights[l], r_max = heights[r];
        while (l < r) {
            if (l_max < r_max) {
                res += l_max - heights[l];
                l++;
                l_max = max(l_max, heights[l]);
            } else {
                res += r_max - heights[r];
                r--;
                r_max = max(r_max, heights[r]);
            }
        }
        return res;
    }
};
