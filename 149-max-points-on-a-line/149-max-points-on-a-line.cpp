// Bruteforce | Time Complexity : O(n^3) | Space Complexity : O(1)
class Solution_1 {
public:
    int maxPoints(vector<vector<int>> &points) {
        int res = 0, n = points.size();
        if (n <= 2) return n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                int cnt = 2;
                for (int k = 0; k < n && k != i && k != j; k++) {
                    int x = points[k][0], y = points[k][1];
                    if ((y2 - y1) * (x - x1) == (x2 - x1) * (y - y1)) cnt++;
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};


// Optimal | Time Complexity : O(n^2) | Space Complexity : O(n)
class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int n = points.size(), res = 0;
        if (n <= 2) return n;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> mp;
            int dup = 0;
            double slope = 0.0;
            for (int j = 0; j < n; j++) {
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                int dy = y2 - y1, dx = x2 - x1;
                if (dy == 0 && dx == 0) {
                    dup++;
                    continue;
                }
                if (dx != 0) slope = dy * 1.0 / dx;
                else slope = INT_MAX;
                mp[slope]++;
            }
            if (mp.empty()) res = dup;
            else {
                for (auto &[_slope, cnt] : mp) {
                    res = max(res, cnt + dup);
                }
            }
        }
        return res;
    }
};
