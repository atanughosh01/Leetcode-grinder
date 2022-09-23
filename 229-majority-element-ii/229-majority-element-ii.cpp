class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        map<int, int> freq;
        vector<int> res;
        for (int &x : nums) freq[x]++;
        for (auto &[key, val] : freq) {
            if (val > n/3) {
                res.push_back(key);
            }
        }
        return res;
    }
};
