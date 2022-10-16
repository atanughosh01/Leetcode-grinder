class Solution_1 {
public:
	long long countSubarrays(vector<int> &nums, int minK, int maxK) {
		long long res = 0;
		bool minFound = false, maxFound = false;
		int start = 0, minStart = 0, maxStart = 0;
		for (int i = 0; i < nums.size(); i++) {
			int num = nums[i];
			if (num < minK || num > maxK) {
				minFound = maxFound = false;
				start = i + 1;
			}
			if (num == minK) {
				minFound = true;
				minStart = i;
			}
			if (num == maxK) {
				maxFound = true;
				maxStart = i;
			}
			if (minFound && maxFound) {
				res += (min(minStart, maxStart) - start + 1);
			}
		}
		return res;
	}
};



class Solution {
public:
	long long countSubarrays(vector<int> &nums, int minK, int maxK) {
		long long res = 0;
		int  j = 0, jmin = -1, jmax = -1, n = nums.size();
		for (int i = 0; i < n; ++i) {
			if  (nums[i] < minK || nums[i] > maxK) {
				jmin = jmax = -1;
				j = i + 1;
			}
			if (nums[i] == minK) jmin = i;
			if (nums[i] == maxK) jmax = i;
			res += max(0, min(jmin, jmax) - j + 1);
		}
		return res;
	}
};
