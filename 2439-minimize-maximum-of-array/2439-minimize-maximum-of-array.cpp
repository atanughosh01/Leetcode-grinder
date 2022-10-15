typedef long long ll;


class Solution_1 {
public:
	int minimizeArrayValue(vector<int> &nums) {
		ll sum = 0, mx = 0, n = nums.size();
		for (ll i = 0; i < n; i++) {
			sum += nums[i];
            ll avg = ceil((double)sum / (i + 1));
			mx = max(mx, avg);
		}
		return (int)mx;
	}
};



class Solution {
public:
	int minimizeArrayValue(vector<int> &nums) {
		ll sum = 0, mx = 0, n = nums.size();
		for (ll i = 0; i < n; i++) {
			sum += nums[i];
			mx = max(mx, (sum + i) / (i + 1));
		}
		return (int)mx;
	}
};
