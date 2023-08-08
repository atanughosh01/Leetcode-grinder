class Solution {
public:
	int search(vector<int> &nums, int target) {
		int n = nums.size();
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++) {
			mp[nums[i]] = i;
		}
		sort(nums.begin(), nums.end());
		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			if (target == nums[mid]) {
				return mp[target];
			}
			if (target < nums[mid]) r = mid - 1;
			if (target > nums[mid]) l = mid + 1;
		}
		return -1;
	}
};
