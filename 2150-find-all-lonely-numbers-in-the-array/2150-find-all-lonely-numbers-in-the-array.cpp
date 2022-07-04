class Solution {
private:
    bool binSrch(vector<int> &arr, int find) {
        int l = 0, r = arr.size() - 1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (find == arr[mid]) return true;
            if (find < arr[mid]) r = mid - 1;
            if (find > arr[mid]) l = mid + 1;
        }
        return false;
    }
public:
    vector<int> findLonely(vector<int> &nums) {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int num : nums) mp[num]++;
        sort(nums.begin(), nums.end());
        for (int num : nums) {
            if (mp[num] == 1 && !binSrch(nums, num+1) && !binSrch(nums, num-1)) {
                res.push_back(num);
            }
        }
        return res;
    }
};
