class Solution_1 {
public:
	int removeDuplicates(vector<int> &nums) {
		int i = 0;
		for (int n : nums) {
			if (i < 2 || n > nums[i - 2]) {
				nums[i++] = n;
			}
		}
		return i;
	}
};


class Solution {
public:


	int removeDuplicates(vector<int> &nums) {
		int n = nums.size(), cnt = 0;
		for (int i = 2; i < n; i++) {
			if (nums[i] == nums[i - 2 - cnt]) cnt++;
			else nums[i - cnt] = nums[i];
		}
		return n - cnt;
	}
};
