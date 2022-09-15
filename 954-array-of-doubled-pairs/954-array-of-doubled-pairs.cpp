class Solution {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> mp;
        vector<int> keys;
        for (int &x : arr) mp[x]++;
        for (auto &[key, val] : mp) {
            keys.push_back(key);
        }
        sort(keys.begin(), keys.end(), [](const int &a, const int &b) {
            return abs(a) < abs(b);
        });
        for (int &key : keys) {
            if (mp[key] > mp[2 * key]) {
                return false;
            }
            mp[2 * key] -= mp[key];
        }
        return true;
    }
};
