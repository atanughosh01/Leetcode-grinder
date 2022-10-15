class Solution {
public:
	int minimizeArrayValue(vector<int> &nums) {
		long long sum = 0, mx = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			mx = max(mx, (sum + i) / (i + 1));
		}
		return (int)mx;
	}
};
