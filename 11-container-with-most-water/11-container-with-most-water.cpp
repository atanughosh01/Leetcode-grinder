class Solution_1 {
public:
    int maxArea(vector<int> &height) {
        int n = (int)height.size();
        int ans = INT_MIN;
        for (int i=0; i<n; i++) {
            for (int j=0; j!=i, j<n; j++) {
                int A = abs(i-j) * min(height[i], height[j]);
                ans = max(ans, A);
            }
        }
        return ans;
    }
};



class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = (int)height.size();
        int ans = INT_MIN, l = 0, r = n-1;
        while (l <= r) {
            int A = (r-l)*min(height[l], height[r]);
            ans = max(ans, A);
            if (height[r] > height[l]) l++;
            else if (height[r] < height[l]) r--;
            else {
                l++;
                r--;
            }
        }
        return ans;
    }
};
