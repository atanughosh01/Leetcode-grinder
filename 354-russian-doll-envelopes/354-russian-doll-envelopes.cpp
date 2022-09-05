class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) {
            return (a[1] > b[1]);
        }
        return (a[0] < b[0]);
    }
public:
    int maxEnvelopes(vector<vector<int>> &env) {
        int n = env.size();
        sort(env.begin(), env.end(), cmp);
        vector<int> res;
        for (int i = 0; i < n; i++){
            int elm = env[i][1];
            int idx = lower_bound(res.begin(), res.end(), elm) - res.begin();
            if (idx >= res.size()) res.push_back(elm);
            else res[idx] = elm;
        }
        return res.size();
    }
};
