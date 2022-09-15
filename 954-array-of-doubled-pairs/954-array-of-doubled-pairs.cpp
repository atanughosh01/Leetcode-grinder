class Solution_1 {
public:
    bool canReorderDoubled(vector<int> &arr) {
        unordered_map<int, int> mp;
        long long sum = 0;
        for (int &x : arr) {
            sum += x;
            mp[x]++;
        }
        if (sum % 3 != 0) return false;
        vector<int> keys;
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



class Solution_2 {
public:
    bool canReorderDoubled(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        long long sum = 0;
        for (int &x : arr) {
            sum += x;
            mp[x]++;
        }
        if (sum % 3 != 0) return false;
        for (int &x : arr) {
            if (mp[x] == 0) continue;
            if (x < 0 && x % 2 != 0) return false;
            int y = x > 0 ? x*2 : x/2;
            if (mp[y] == 0) return false;
            mp[x]--, mp[y]--;
        }
        return true;
    }
};




class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int> mp;
        long long sum = 0;
        for (int &x : arr) {
            sum += x;
            mp[x]++;
        }
        if (sum % 3 != 0) return false;
        for (int &x : arr) {
            if (mp[x] && mp[x*2]) {
                mp[x]--, mp[x*2]--;
            }
        }
        for (auto &[key, val] : mp) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }
};
