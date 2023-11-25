class Solution {
public:
    int maxSubArray(vector<int> &nums) {      
        // int maxSoFar = 0, res = INT_MIN;      
        int maxSoFar = 0, res = -10000;
        for (int &num : nums) {
            maxSoFar = max(num, maxSoFar + num);
            res = max(res, maxSoFar);
        }
        return res;
    }
};
