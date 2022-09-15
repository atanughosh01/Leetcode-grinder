// Multiset Solution | O(n*log(n)) Time | O(n) Space | n = changed.length
class Solution_1 {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        if (changed.size() % 2) return {};
        multiset<int> s(changed.begin(), changed.end());
        vector<int> original;
        for (int i = 0; i < changed.size(); i += 2) {
            int n = *s.begin();
            original.push_back(n);
            s.erase(s.begin());
            if (s.find(2 * n) == s.end()) return {};
            s.erase(s.find(2 * n));
        }
        return original;
    }
};


// Most Optimal | O(n*log(n)) Time | O(n) Space | n = changed.length
class Solution_2 {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        if (changed.size() % 2) return {};
        sort(changed.begin(), changed.end());
        unordered_map<int, int> mp;
        vector<int> original;
        for (int &x : changed) mp[x]++;
        for (int &x : changed) {
            if (mp[x] == 0) continue;
            if (mp[x*2] == 0) return {};
            original.push_back(x);
            mp[x]--, mp[x*2]--;
        }
        return original;
    }
};


// Most Optimal | O(n + k*log(k)) Time | O(n) Space | n = changed.length, k = no. of unique elements
class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        if (changed.size() % 2) return {};
        unordered_map<int, int> mp;
        for (int &x : changed) mp[x]++;
        vector<int> keys;
        for (auto &[key, val] : mp) {
            keys.push_back(key);
        }
        sort(keys.begin(), keys.end());
        vector<int> original;
        for (int &y : keys) {
            if (mp[y] > mp[2 * y]) return {};
            for (int i = 0; i < mp[y]; i++) {
                original.push_back(y);
                mp[2 * y]--;
            }
        }
        return original;
    }
};
