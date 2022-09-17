// O((m + n) * log(m + n))
class Solution_1 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        for(int i=0; i<n; ++i) {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
};


// O(m + n)
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int a = m - 1, b = n - 1;
        int i = m + n - 1;
        while (a >= 0 && b >= 0) {
            if (nums1[a] > nums2[b]) nums1[i--] = nums1[a--];
            else nums1[i--] = nums2[b--];
        }
        while (b >= 0) nums1[i--] = nums2[b--];
    }
};
