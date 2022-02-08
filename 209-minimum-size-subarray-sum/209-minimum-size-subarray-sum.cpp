// O(NlogN) using Prefix Sum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size(), len = INT_MAX;
        vector<int> sums(n+1);
        sums[0] = 0;
        for (int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for (int i = n; i >= 0; i--) {
            if(sums[i] < target)
                break;
            int j = upper_bound(sums.begin(), sums.end(), sums[i]-target) - sums.begin();
            len = min(len, i - j + 1);
        }
        if(len==INT_MAX) return 0;
        else return len;
    }
};

/*
// O(NlogN) using Two Pointers
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int len=INT_MAX, l=0, r=0, sum=0;
        while(r < n) {
            sum += nums[r];
            while(sum >= target){
                len = min(len, r - l + 1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        if(len==INT_MAX) return 0;
        else return len;
    }
};
*/