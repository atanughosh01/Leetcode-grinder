// Bruteforce | Time Complexity : O(n^3) | Space Complexity : O(1)
class Solution {
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
