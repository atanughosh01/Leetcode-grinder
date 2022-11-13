class Solution_1 {
public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		unordered_map<int, int> mp;
		for (int &num : nums) mp[num]++;
		vector<pair<int, int>> v(mp.begin(), mp.end());
		sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        });
		nums.clear();
		for (int i = 0; i < k; i++) {
			nums.push_back(v[i].first);
		}
		return nums;
	}
};



class Solution {
public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		unordered_map<int, int> mp;
		for (int &num : nums) mp[num]++;
		vector<pair<int, int>> v(mp.begin(), mp.end());
		sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
		nums.clear();
		for (int i = 0; i < k; i++) {
			nums.push_back(v[i].first);
		}
		return nums;
	}
};
