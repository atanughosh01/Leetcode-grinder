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
