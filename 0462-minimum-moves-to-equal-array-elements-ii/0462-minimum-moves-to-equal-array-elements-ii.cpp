class Solution_1 {
public:
    int minMoves2(vector<int> &nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        int median = nums[n/2];
        for (int num : nums) {
            ans += abs(median - num);
        }
        return ans;
    }
};


class Solution_2 {
public:
    int minMoves2(vector<int> &nums) {
        int n = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n/2; i++){
            ans += nums[n-1-i] - nums[i];
        }
        return ans;
    }
}; 


class Solution {
public:
    int minMoves2(vector<int> &nums) {
        int n = nums.size(), ans = 0;
        nth_element(nums.begin(), nums.begin() + (n/2), nums.end());
        int median = nums[n / 2];
        for (int i = 0; i < n; i++){
            ans += abs(median - nums[i]);
        }
        return ans;
    }
};
