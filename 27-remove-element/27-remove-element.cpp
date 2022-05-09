class Solution {
public:
    static int removeElement(vector<int> &nums, int val) {
        auto itr = remove(nums.begin(), nums.end(), val);
        return distance(nums.begin(), itr);
    }
};
