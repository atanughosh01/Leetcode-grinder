// TC: O(N), SC: O(1), linear search
class Solution_1 {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = (int)(nums.size());
        int first = -1, last = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target && first == -1) {
                first = i;
            }
            if (nums[n-i-1] == target && last == -1) {
                last = n-i-1;
            }
            if (first != -1 && last != -1) {
                break;
            }
        }
        return {first, last};
    }
};



// TC: O(log(N)), SC: O(1), binary search
class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = (int)(nums.size());
        if (n == 0) return {-1, -1};
        int l = 0, r = n - 1;
        int first = -1, last = -1;
        while (l < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if (nums[l] == target) first = l;
        else return {-1, -1};
        r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid + 1] > target) r = mid;
            else l = mid + 1;
        }
        last = r;
        return {first, last};
    }
};
