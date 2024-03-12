class Solution_1 {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) return 0;
    
        // for sorting on basis of (i+1)-th column
        sort(points.begin(), points.end(), [] (auto &v1, auto &v2, int i = 1) {
            return v1[i] < v2[i];
        });
        int endX = points[0][1], cnt = 1;
        for (auto &point : points) {
            int startX = point[0];
            if (startX > endX) {
                cnt++;
                endX = point[1];
            }
        }
        return cnt;
    }
};


class Solution_2 {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) return 0;
    
        // for sorting on basis of 1st column
        sort(points.begin(), points.end());
        int startX = points[0][0], endX = points[0][1], cnt = 1;
        for (auto &point : points) {
            if (point[0] > endX) {
                cnt++;
                startX = point[0];
                endX = point[1];
            } else {
                startX = max(point[0], startX);
                endX = min(point[1], endX);
            }
        }
        return cnt;
    }
};


class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        if (points.size() == 0) return 0;
        sort(points.begin(), points.end());
        int endX = points[0][1], cnt = 1;
        for (auto &point : points) {
            if (point[0] > endX) {
                cnt++;
                endX = point[1];
            }
            endX = min(point[1], endX);
        }
        return cnt;
    }
};
