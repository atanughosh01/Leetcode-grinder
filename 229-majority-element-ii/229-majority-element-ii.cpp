// O(n) time | O(n) Space | n = nums.size();
class Solution_1 {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
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


// O(n) time | O(1) Space | n = nums.size();
class Solution {
public:
    vector<int> majorityElement(vector<int> &nums) {
        int n = nums.size();
        int y = -1, z = -1, cy = 0, cz = 0;
        for (int &x : nums) {
            if (x == y) cy++;
            else if (x == z) cz++;
            else if (cy == 0) y = x, cy = 1;
            else if (cz == 0) z = x, cz = 1;
            else cy--, cz--;
        }
        cy = cz = 0;
        for (int &x : nums) {
            if (x == y) cy++;
            else if (x == z) cz++;
        }
        vector<int> res;
        if (cy > n / 3) res.push_back(y);
        if (cz > n / 3) res.push_back(z);
        return res;
    }
};
