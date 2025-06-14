/*
    class Solution {
    public:
        vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
            vector<bool> res;
            for (auto i = 0; i < l.size(); ++i) {
                if (r[i] - l[i] < 2) res.push_back(true);
                else {
                    vector<int> n(begin(nums) + l[i], begin(nums) + r[i] + 1);
                    int j = 2;
                    sort(begin(n), end(n));
                    for (; j < n.size(); ++j)
                        if (n[j] - n[j - 1] != n[1] - n[0])
                            break;
                    res.push_back(j == n.size());
                }
            }
            return res;
        }
    };
*/



class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &n, vector<int> &l, vector<int> &r) {
        vector<bool> res;
        for (auto i = 0; i < l.size(); ++i) {
            int mn_e = INT_MAX, mx_e = INT_MIN, len = r[i] - l[i] + 1, j = l[i];
            for (int j = l[i]; j <= r[i]; ++j) {
                mn_e = min(mn_e, n[j]);
                mx_e = max(mx_e, n[j]);
            }
            if (mx_e == mn_e) res.push_back(true);
            else if ((mx_e - mn_e) % (len - 1)) res.push_back(false);
            else {
                vector<bool> diffs(len);
                int pat = (mx_e - mn_e) / (len - 1);
                for (; j <= r[i]; ++j) {
                    if ((n[j] - mn_e) % pat || diffs[(n[j] - mn_e) / pat]) break;
                    diffs[(n[j] - mn_e) / pat] = true;
                }
                res.push_back(j > r[i]);
            }
        }
        return res;
    }
};
