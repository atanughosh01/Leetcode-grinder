class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        const int N = 1e6+10;
        int freq[N]{0}, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                freq[abs(nums[i] - nums[j])]++;
            }
        }
        for (int i = 0; i < N; i++) {
            if (freq[i] >= k) return i;
            k -= freq[i];
        }
        return 0;
    }
};
