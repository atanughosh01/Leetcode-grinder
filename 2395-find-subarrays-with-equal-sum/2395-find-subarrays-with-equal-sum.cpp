class Solution_1 {
public:
    bool findSubarrays(vector<int> &nums) {
        int n = nums.size();
        int arr[n - 1];
        for (int i = 1; i < n; i++) {
            arr[i - 1] = nums[i] + nums[i - 1];
        }
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (arr[i] == arr[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool findSubarrays(vector<int> &nums) {
        int n = nums.size();
        unordered_set<int> ans;
        for(int i = 1; i < n; i++){
            ans.insert(nums[i] + nums[i - 1]);
        }
        if (ans.size() == (nums.size() - 1)){
            return false;
        }
        return true;
    }
};
