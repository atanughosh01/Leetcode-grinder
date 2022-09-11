class Solution {
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k) {
        const int mod = 1e9 + 7;
        vector<pair<int, int>> engineers(n);
        for (int i = 0; i < n; ++i) {
            engineers[i] = {efficiency[i], speed[i]};
        }
        sort(engineers.rbegin(), engineers.rend());
        long long sumS = 0, res = 0;
        priority_queue<int, vector<int>, greater<int>> pq; //min heap
        for (auto &[e, s] : engineers) {
            pq.emplace(s);
            sumS += s;
            if (pq.size() > k) {
                sumS -= pq.top();
                pq.pop();
            }
            res = max(res, sumS * e);
        }
        return res % mod;
    }
};
