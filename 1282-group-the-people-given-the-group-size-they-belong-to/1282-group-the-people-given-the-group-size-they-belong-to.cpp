class Solution_1 {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<vector<int>> res, groups(groupSizes.size() + 1);
        for (int i = 0; i < groupSizes.size(); ++i) {
            groups[groupSizes[i]].push_back(i);
            if (groups[groupSizes[i]].size() == groupSizes[i]) {
                res.push_back({});
                swap(res.back(), groups[groupSizes[i]]);
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); i++) {
            m[groupSizes[i]].push_back(i);
            if (m[groupSizes[i]].size() == groupSizes[i]) {
                res.push_back(m[groupSizes[i]]);
                m[groupSizes[i]].clear();
            }
        }
        return res;
    }
};
