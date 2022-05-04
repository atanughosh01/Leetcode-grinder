class Solution {
public:
	int maxOperations(vector<int> &nums, int k) {
		int cnt  = 0;
		unordered_map<int, int> mp;
		for (int num : nums) mp[num]++;
		for (int num : nums) {
			auto itr = mp.find(k - num);
			if (itr != mp.end() && mp[k - num] > 0) {
				mp[k - num]--;
				if (mp[num] > 0) {
					mp[num]--;
					cnt++;
				}
			}
		}
		return cnt;
	}
};
