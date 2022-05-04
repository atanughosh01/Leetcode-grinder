class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (int x : nums) mp[x]++;
        int cnt  = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            auto itr = mp.find(k - nums[i]);
			if (itr != mp.end() && mp[k - nums[i]] > 0) {
				mp[k - nums[i]]--;
				if (mp[nums[i]] > 0) {
					mp[nums[i]]--;
					cnt++;
				}
			}
        }
        return cnt;
    }
};
