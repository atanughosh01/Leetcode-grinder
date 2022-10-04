class Solution {
private:
    int findMaxIndex(vector<int> &nums2, long long val, long long midval) {
        int n = nums2.size(), l = 0, r = n - 1, res = -1;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (val * nums2[mid] <= midval) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res + 1;
    }

    int findMinIndex(vector<int> &nums2, long long val, long long midval) {
        int n = nums2.size(), l = 0, r = n - 1, res = n;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (val * nums2[mid] <= midval) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return n - res;
    }

    bool check(long long midval, vector<int> &nums1, vector<int> &nums2, long long k) {
        long long cnt = 0;
        for (int i = 0; i < nums1.size(); i++) {
            long long val = nums1[i];
            if (val == 0 && midval >= 0) cnt += nums2.size();
            else if (val > 0) cnt += findMaxIndex(nums2, val, midval);
            else if (val < 0) cnt += findMinIndex(nums2, val, midval);
        }
        return cnt >= k;
    }

public:
    long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k) {
        long long l = -1e10, r = 1e10, res = -1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(mid, nums1, nums2, k)) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
