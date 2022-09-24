// Bucket Sort | O(n^2) Time | O(m) Space | n = nums.length, m = max of array nums
class Solution_1 {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        const int N = 1e6 + 10;
        int freq[N]{0}, n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                freq[abs(nums[i] - nums[j])]++;
            }
        }
        for (int i = 0; i < N; i++) {
            if (freq[i] >= k) return i;
            k -= freq[i];
        }
        return 0;
    }
};



// Binary Search | O(n * log(m)) Time | O(1) Space | n = nums.length, m = max of array nums
class Solution {
public:
    int smallestDistancePair(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = 1e6;
        while (l < r) {
            int mid = l + (r - l) / 2, cnt = 0;
            for (int i = 0, j = 0; i < n; i++) {    // whole for loop takes O(n) time
                while (j < n && nums[j] - nums[i] <= mid) j++;
                cnt += j - (i + 1);
            }
            if (cnt < k) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};
