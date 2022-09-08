class Solution {
private:
    int atMost(vector<int> &arr, int k) {
        int cnt = 0, sum = 0, l = 0, r = 0;
        if (k < 0) return 0;
        while (r < arr.size()) {
            sum += arr[r];
            while (sum > k) {
                sum -= arr[l++];
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};
