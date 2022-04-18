class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = (int)(nums.size());
        int zero=0, one=0, two=0;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) zero++;
            if (nums[i] == 1) one++;
            if (nums[i] == 2) two++;
        }
        for (int i=0; i<n; i++) {
            if (i < zero) nums[i] = 0;
            if (i >= zero && i < (zero + one)) nums[i] = 1;
            if (i >= (zero + one)) nums[i] = 2;
        }
    }
};
