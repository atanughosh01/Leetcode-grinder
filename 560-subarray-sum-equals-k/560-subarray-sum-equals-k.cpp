class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0, cnt = 0;
        unordered_map<int,int> table;
        table[0]++;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            cnt += table[sum-k];
            table[sum]++;
        }
        return cnt;
    }
};
