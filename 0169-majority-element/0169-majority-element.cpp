class Solution_1 {
public:
    int majorityElement(vector<int> &nums) {
        int n = nums.size(), res = 0;
        unordered_map<int, int> freq;
        for (int &x : nums) freq[x]++;
        for (auto &[key, val] : freq) {
            if (val > n/2) return key;
        }
        return -1;
    }
};


class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int res = 0, cnt = 0;
        for (int &x : nums) {
            if (cnt == 0) res = x;
            cnt += (x == res) ? 1 : -1;
        }
        return res;
    }
};
