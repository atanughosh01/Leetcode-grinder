// O(N^2) APPROACH
class Solution_1 {
public:    
    vector<int> twoSum(vector<int> &nums, int tar) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == tar) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};



// O(N) APPROACH
class Solution {
public:    
    vector<int> twoSum(vector<int> &nums, int tar) {
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto idx = mp.find(tar - nums[i]);
            if (idx != mp.end() && idx->second != i) {
                return {i, (idx->second)};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
