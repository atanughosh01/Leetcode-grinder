class Solution_1 {
public:
    int maxOperations(vector<int> &nums, int k) {
        int cnt = 0;
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


class Solution {
public:
	int maxOperations(vector<int> &nums, int k) {
		int res = 0;
		unordered_map<int, int> mp;
		for (int &num : nums) mp[num]++;
		for (auto &[num, freq] : mp) {
			if (k - num == num) res += freq / 2;
			else if (mp.count(k - num)) {
				int mn = min(freq, mp[k - num]);
				res += mn;
				mp[num] -= mn;
				mp[k - num] -= mn;
			}
		}
		return res;
	}
};
