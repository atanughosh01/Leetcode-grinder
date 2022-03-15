/*
    class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = (int)nums.size();
            vector<int> less, greater, equal, res;
            for(int i=0; i<n; i++) {
                if(nums[i] < pivot) less.emplace_back(nums[i]);
                if(nums[i] > pivot) greater.emplace_back(nums[i]);
                if(nums[i] == pivot) equal.emplace_back(nums[i]);
            }
            for(int x : less) res.emplace_back(x);
            for(int y : equal) res.emplace_back(y);
            for(int z : greater) res.emplace_back(z);
            return res;
        }
    };
*/


class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int low = 0, same = 0, high = nums.size();
        for(auto n : nums) {
            if(n < pivot)  ++same; 
            else if(n > pivot) --high;
        }
        vector<int> res(nums.size());
        for(auto n : nums) {
            if(n < pivot) res[low++] = n; 
            else if(n == pivot) res[same++] = n;
            else res[high++] = n;
        }
        return res;
    }
};
