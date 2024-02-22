class Solution_1 {
   public:
    int findJudge(int n, vector<vector<int>> &trust) {
        // int N = (int)trust.size();
        int label = -1;
        for (int i = 0; i < n; i++) {
            label = trust[i][1];
            for (int j = 0; j < n; j++) {
                if (i == j) j++;
                if (label == trust[j][0]) continue;
                // else label = trust[i][1];
            }
        }
        return label;
    }
};

class Solution {
   public:
    int findJudge(int N, vector<vector<int>> &trust) {
        vector<int> count(N + 1, 0);
        for (auto &t : trust) {
            count[t[0]]--;
            count[t[1]]++;
        }
        for (int i = 1; i <= N; ++i) {
            if (count[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};
