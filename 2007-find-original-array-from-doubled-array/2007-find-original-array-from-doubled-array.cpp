class Solution {
public:
    vector<int> findOriginalArray(vector<int> &changed) {
        if (changed.size() % 2) return {};
        multiset<int> s(changed.begin(), changed.end());
        vector<int> res;
        for (int i = 0; i < changed.size(); i += 2) {
            int n = *s.begin();
            res.push_back(n);
            s.erase(s.begin());
            if (s.find(2 * n) == s.end()) return {};
            s.erase(s.find(2 * n));
        }
        return res;
    }
};
