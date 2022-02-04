// class Solution {
// public:
// 	int findMaxLength(vector<int>& nums) {
// 		int c0 = 0, c1 = 0, len = 0;
// 		int n = (int)nums.size();
// 		for (int i = 0; i < n; i++) {
// 			if (nums[i]) c1++;
// 			else c0++;
// 			if (i % 2) {
// 				if (c0 == c1)
// 					len = i;
// 			}
// 		}
// 		return len + 1;
// 	}
// };


/*
// TC: O(N^2) BruteForce TLE Solution

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int len = 0;
		int n = (int)nums.size();
		for (int i = 0; i < n; i++) {
			int c0 = 0, c1 = 0;
			for (int j = i; j < n; j++) {
				if (nums[j]) c1++;
				else c0++;
				if (c0 == c1) {
					len = max(len, j - i + 1);
				}
			}
		}
		return len;
	}
};

*/

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int len = 0, sum = 0;
		int n = (int)nums.size();
		vector<int> arr(2 * n + 1, INT_MIN);
		arr[n] = -1;
		for (int i = 0; i < n; i++) {
			sum += (nums[i] ? 1 : -1);
			if (arr[sum + n] >= -1)
				len = max(len, i - arr[sum + n]);
			else
				arr[sum + n] = i;
		}
		return len;
	}
};
