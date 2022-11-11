class Solution {
public:
	int removeDuplicates(vector<int> &nums) {
		int n = nums.size(), i = 0, j = 0;
		if (n == 1) return 1;
		while (i < n) {
			int t = nums[i];
			nums[j++] = nums[i++];
			while (i < n && t == nums[i]) i++;
		}
		return j;
	}
};
