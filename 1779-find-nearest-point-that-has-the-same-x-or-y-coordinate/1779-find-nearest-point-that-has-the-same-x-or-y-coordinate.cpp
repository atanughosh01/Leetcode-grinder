class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
        int res = -1, mn = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int manHatDist = abs(x - points[i][0]) + abs(y - points[i][1]);
                if (manHatDist < mn) {
                    mn = manHatDist;
                    res = i;
                }
            }
        }
        return res;
    }
};
