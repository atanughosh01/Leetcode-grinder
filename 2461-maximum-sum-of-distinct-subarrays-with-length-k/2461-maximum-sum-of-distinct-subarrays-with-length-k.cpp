class Solution_1 {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        long long n = nums.size(), res = 0;
        long long l = 0, r = 0, sum = 0;
        unordered_set<int> st;
        vector<int> v;
        while (r < n) {
            sum += nums[r];
            st.insert(nums[r]);
            if (r - l + 1 == k) {
                if (st.size() == k) {
                    v.push_back(sum);
                }
                st.clear();
                r = ++l;
                sum = 0;
            } else {
                r++;
            }
        }
        return v.empty() ? 0 : *max_element(v.begin(), v.end());
    }
};


class Solution {
public:
	long long maximumSubarraySum(vector<int> &nums, int k) {
		int n = nums.size();
		long long res = 0, sum = 0;
		unordered_map<int, int> mp;
		for (int i = 0; i < n; i++) {
			mp[nums[i]]++;
			sum += nums[i];
			if (i >= k) {
				mp[nums[i - k]]--;
				sum -= nums[i - k];
				if (!mp[nums[i - k]]) {
					mp.erase(nums[i - k]);
				}
			}
			if (mp.size() == k) {
				res = max(res, sum);
			}
		}
		return res;
	}
};
