class Solution {
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
		for (int &x : nums2) nums1.push_back(x);
		int n = nums1.size();
		sort(nums1.begin(), nums1.end());
		if (n % 2) return (double)nums1[n / 2];
		return (double)(nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
	}
};
