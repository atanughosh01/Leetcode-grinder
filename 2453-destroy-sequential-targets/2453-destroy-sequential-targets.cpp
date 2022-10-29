class Solution {
public:
	int destroyTargets(vector<int> &nums, int space) {
		int n = nums.size(), mx = INT_MIN, mn = INT_MAX;
		sort(nums.begin(), nums.end());
		map<int, int> mp;
		set<int> st;
		for (int i = 0; i < n; i++) {
			int x = nums[i] / space;
			x = nums[i] - x * space;
			if (x == 0) x = space;
			mp[x]++;
		}
		for (auto &[k, v] : mp) {
			mx = max(mx, v);
		}
		for (auto &[k, v] : mp) {
			if (v == mx) {
				st.insert(k);
			}
		}
		for (int i = 0; i < n; i++) {
			int x = nums[i] / space;
			x = nums[i] - x * space;
			if (x == 0) x = space;
			if (st.find(x) != st.end()) {
				mn = min(mn, nums[i]);
			}
		}
		return mn;
	}
};
