// O(N^2) APPROACH
class Solution {
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
class Solution_1 {
public:    
    vector<int> twoSum(vector<int> &nums, int tar) {        
        int n = (int)nums.size();
        unordered_map<int,int> ump;
        for(int i=0; i<n; i++) {
            auto idx = ump.find(tar - nums[i]);
            if(idx != ump.end() && idx->second != i) {
                return {i, (idx->second)};
            }
            ump[nums[i]] = i;
        }
        return {};
      }
};
