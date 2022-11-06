class Solution_1 {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        long long sum = 0, res = 0;
        int l = 0, r = 0, n = nums.size();
        unordered_set<int> st;
        while (r < n) {
            sum += nums[r];
            st.insert(nums[r]);
            if (r - l + 1 == k) {
                if (st.size() == k) {
                    res = max(res, sum);
                }
                st.clear();
                r = ++l;
                sum = 0;
            } else {
                r++;
            }
        }
        return res;
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
			sum += nums[i];             // add from the front
			if (i >= k) {
				mp[nums[i - k]]--;
				sum -= nums[i - k];     // substract from the back
				if (mp[nums[i - k]] == 0) {
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
