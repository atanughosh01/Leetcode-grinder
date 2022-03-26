class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k, 0);
        unordered_map<int, unordered_set<int>> mp;
        for (auto &log : logs) {
            mp[log[0]].insert(log[1]);
        }
        for (auto &user : mp) {
            int idx = (user.second).size()-1;
            res[idx]++;
        }
        return res;
    }
};
