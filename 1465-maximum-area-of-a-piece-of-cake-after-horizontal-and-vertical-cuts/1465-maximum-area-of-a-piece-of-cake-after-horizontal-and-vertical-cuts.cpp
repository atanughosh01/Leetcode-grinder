class Solution {
public:
    int maxArea(int h, int w, vector<int> &hc, vector<int> &vc) {
        const long long MOD = 1e9 + 7;
        hc.push_back(h);
        vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int max_h = hc[0], max_v = vc[0];
        for (int i = 1; i < hc.size(); i++) {
            max_h = max(max_h, hc[i] - hc[i-1]);
        }
        for (int j = 1; j < vc.size(); j++) {
            max_v = max(max_v, vc[j] - vc[j-1]);
        }
        return (max_h * 1ll * max_v) % MOD;
    }
};
