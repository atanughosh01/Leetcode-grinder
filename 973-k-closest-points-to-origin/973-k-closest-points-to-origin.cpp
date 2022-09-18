class Solution {
private:
    double dist(int x1, int y1, int x2, int y2) {
        int sq = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
        return sqrt(sq);
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        int n = points.size();
        if (k == n) return points;
        vector<vector<int>> res;
        map<double, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            double d = dist(points[i][0], points[i][1], 0, 0);
            mp[d].push_back(i);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vector<int> v = it->second;
            for (int i = 0; i < v.size(); i++) {
                res.push_back(points[v[i]]);
                if (k == res.size()) return res;
            }
        }
        return {};
    }
};
