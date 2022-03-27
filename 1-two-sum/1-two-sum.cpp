class Solution {
public:    
    vector<int> twoSum(vector<int>& nums, int tar) {
        
        // O(N^2) APPROACH
        /*
        for(int i=0; i<(int)nums.size(); i++) {
            for(int j=i+1; j<(int)nums.size(); j++) {
                if(nums[i]+nums[j] == tar) {
                    return {i, j};
                }
            }
        }
        return {};
        */
        
        
        // O(N) APPROACH
        
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
