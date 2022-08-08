class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 1) return 1;
        signed int i=0, j=0, size=0;
        int t;
        while (i <nums.size()) {
            nums[j++] = nums[i];
            t = nums[i];
            ++i;
            while (i < nums.size() && t == nums[i]) ++i;
        }
        return j;
    }
};
