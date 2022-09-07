class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int res = 0, curr = 0;
        for (int value : values) {
            res = max(res, curr + value);
            curr = max(curr, value) - 1;
        }
        return res;
    }
};
