typedef long long ll;

class Solution {
protected:
	string convRangetoStr(vector<int> &v) {
		if ((ll)v.size() == 1) {
			return to_string(v[0]);
		}
		string ff = to_string(v[0]);
		string ss = to_string(v[1]);
		string str = ff + "->" + ss;
		return str;
	}
public:
	vector<string> summaryRanges(vector<int> &nums) {
		ll n = (ll)nums.size();
		if (n == 0) return {};
		if (n == 1) return {to_string(nums[0])};
		if (n == 2) {
			if (nums[1] - nums[0] == 1) {
				return {convRangetoStr(nums)};
			}
			return {to_string(nums[0]), to_string(nums[1])};
		}
		vector<string> list;
		vector<int> range = {nums[0]};
		for (ll i = 0; i < n; ++i) {
			if (i == n - 1) {
				nums.push_back((ll)nums[n - 1] + 2);
			}
			if ((ll)nums[i + 1] - (ll)nums[i] != 1) {
				if (range[0] != nums[i]) {
					range.push_back(nums[i]);
				}
				list.push_back(convRangetoStr(range));
				range = {nums[i + 1]};
			}
		}
		return list;
	}
};
