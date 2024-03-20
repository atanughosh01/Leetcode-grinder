class Solution {
    bool dfs(vector<int> &sidesLength, const vector<int> &matches, int index, const int target) {
        if (index == matches.size()) {
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        }
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) {
                continue;
            }
            int j = i;
            while (--j >= 0) {
                if (sidesLength[i] == sidesLength[j]) {
                    break;
                }
            }
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target)) {
                return true;
            }
            sidesLength[i] -= matches[index];
        }
        return false;
    }
public:
    bool makesquare(vector<int> &sticks) {
        if (sticks.size() < 4) {
            return false;
        }
        int sum = 0;
        for (const int &val: sticks) {
            sum += val;
        }
        if (sum % 4) return false;
        sort(sticks.begin(), sticks.end(), [&](const int &l, const int &r) {
            return l > r;
        });
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, sticks, 0, sum / 4);
    }
};
