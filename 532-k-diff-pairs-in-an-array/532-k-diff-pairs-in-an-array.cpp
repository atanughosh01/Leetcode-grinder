class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = (int)nums.size();
        set<pair<int, int>> s;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                if(abs(nums[i]-nums[j]) == k){
                    int ff = min(nums[i], nums[j]);
                    int ss = max(nums[i], nums[j]);
                    s.insert({ff, ss});
                }
            }
        }
        return (int)s.size();
    }
};
