class Solution {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                res.push_back(i);
            }
        }
        return res;
    }
};



class Solution_2 {
public:
    vector<int> targetIndices(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        sort(nums.begin(), nums.end());
        vector<int> res;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                cout << mid << " ";
                res.push_back(mid);
                l++;
            } else if (nums[mid] > target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << "\n";
        return res;
    }
};
