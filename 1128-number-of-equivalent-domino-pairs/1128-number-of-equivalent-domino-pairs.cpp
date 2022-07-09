class Solution_1 {
public:
    int numEquivDominoPairs(vector<vector<int>> &dom) {
        int n = (int)(dom.size()), cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j != i && j < n; j++) {
                if ((dom[i][0] == dom[j][0] && dom[i][1] == dom[j][1]) 
                || (dom[i][0] == dom[j][1] && dom[i][1] == dom[j][0])) cnt++;
            }
        }
        return cnt;
    }
};



class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dom) {
        int n = (int)(dom.size()), cnt = 0;
        map<pair<int, int>, int> mp;
        for (vector<int> &d : dom) {
            if (d[0] > d[1]) {
                swap(d[0], d[1]);
            }
            mp[make_pair(d[0], d[1])]++;
        }
        for (auto &[key, value] : mp) {
            cnt += value*(value - 1) / 2;
        }
        return cnt;
    }
};
