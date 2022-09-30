class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
        int n = buildings.size();
        vector<vector<int>> ans;
        vector<pair<int, int>> a;
        int cur_ht = 0;
        multiset<int, greater<int>> pq;
        pq.insert(0);
        for (int i = 0; i < n; i++) {
            int st = buildings[i][0];
            int en = buildings[i][1];
            int ht = buildings[i][2];
            a.push_back({st, -ht});
            a.push_back({en, ht});
        }
        sort(a.begin(), a.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if (a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        });
        for (int i = 0; i < a.size(); i++) {
            int pt = a[i].first, ht = a[i].second;
            if (ht < 0) {
                pq.insert(-ht);
            } else {
                auto it = pq.find(ht);
                if (it != pq.end()) pq.erase(it);
            }
            int htt = *pq.begin();
            if (cur_ht != htt) {
                int pt = a[i].first;
                ans.push_back({pt, htt});
                cur_ht = htt;
            }
        }
        return ans;
    }
};
