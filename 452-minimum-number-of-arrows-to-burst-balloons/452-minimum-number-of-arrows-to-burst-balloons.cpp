class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        
        // for sorting on basis of (i+1)-th column
        sort(points.begin(), points.end(), [] (auto& v1, auto& v2, int i=1) {
            return v1[i] < v2[i];
        });
        int endX = points[0][1];
        int cnt = 1;
        for(auto point : points) {
            int startX = point[0];
            if(startX > endX){
                cnt++;
                endX = point[1];
            }
        }
        return cnt;
    }
};
