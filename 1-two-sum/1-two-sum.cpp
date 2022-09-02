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
class Solution_2 {
public:    
    vector<int> twoSum(vector<int> &nums, int tar) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            auto it = mp.find(tar - nums[i]);
            if (it != mp.end() && it->second != i) {
                return {i, (it->second)};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};



// O(N) APPROACH
class Solution {
public:    
    vector<int> twoSum(vector<int> &nums, int tar) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int numToFind = (tar - nums[i]);
            if (mp.find(numToFind) != mp.end()) {
                return {mp[numToFind], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
