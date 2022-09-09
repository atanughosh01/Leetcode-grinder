class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &env) {
        sort(env.begin(), env.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
        });
        vector<int> res;
        for (const vector<int> &v : env) {
            int idx = lower_bound(res.begin(), res.end(), v[1]) - res.begin();
            if (idx >= res.size()) res.push_back(v[1]);
            else res[idx] = v[1];
        }
        return res.size();
    }
};
