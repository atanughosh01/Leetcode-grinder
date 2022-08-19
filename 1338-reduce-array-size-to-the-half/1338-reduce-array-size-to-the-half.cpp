class Solution {
public:
    int minSetSize(vector<int> &arr) {
        unordered_map<int, int> m;
        priority_queue<int> pq;
        for (int n : arr) ++m[n];
        for (auto &p : m) pq.push(p.second);
        int res = 0, cnt = 0;
        while (cnt < arr.size() / 2) {
            res++;
            cnt += pq.top();
            pq.pop();
        }
        return res;
    }
};
