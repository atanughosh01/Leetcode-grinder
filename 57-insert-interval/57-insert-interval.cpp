class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<vector<int>> res;
        for (size_t i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            } else if (intervals[i][0] > newInterval[1]) {
                res.push_back(newInterval);
                newInterval = intervals[i];
            } else {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};
