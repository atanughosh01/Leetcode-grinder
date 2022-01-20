/*

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result = 0;
        for(int i = 0; i < nums.size(); i += 2){
            result += nums[i];
        }
        return result;
    }
};

*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int buckets[20001] = {0};
        for(auto n : nums) {
            ++buckets[n + 10000];
        }
        int sum = 0;
        for(int i = 0, used = 0; used < nums.size();) {
            if(buckets[i] == 0) {
                ++i;
            } else {
                if(used % 2 == 0)
                    sum += (i - 10000);
                --buckets[i];
                ++used;
            }
        }
        return sum;
    }
};
