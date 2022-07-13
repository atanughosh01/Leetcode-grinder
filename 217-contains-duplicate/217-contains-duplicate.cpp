class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (int x : nums)
            s.insert(x);
        if (nums.size() != s.size())
            return true;
        return false;
    }
};
