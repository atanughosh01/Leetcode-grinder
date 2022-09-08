class Solution_1 {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int res = INT_MIN, n = values.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int score = values[i] + values[j] + i - j;
                res = max(res, score);
            }
        }
        return res;
    }
};



class Solution_2 {
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



class Solution {
public:
    int maxScoreSightseeingPair(vector<int> &values) {
        int maxScore = 0, maxSum = values[0] + 0;
        for (int i = 1; i < values.size(); i++) {
            maxScore = max(maxScore, maxSum + values[i] - i);
            maxSum = max(maxSum, values[i] + i);
        }
        return maxScore;
    }
};
