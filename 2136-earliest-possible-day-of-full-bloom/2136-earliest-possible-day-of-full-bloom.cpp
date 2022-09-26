class Solution {
public:
    int earliestFullBloom(vector<int> &PT, vector<int> &GT) {
        int n = PT.size(), res = 0;
        vector<pair<int, int>> GP(n);
        for (int i = 0; i < n; i++) {
            GP[i] = {GT[i], PT[i]};
        }
        sort(GP.begin(), GP.end());
        for (auto &[g, p] : GP) {
            res = max(res, g);
            res += p;
        }
        return res;
    }
};
