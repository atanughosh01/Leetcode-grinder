class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        unordered_map<int, string> mp;
        for (int i = 0; i < names.size(); i++) {
            mp[heights[i]] = names[i];
        }
        sort(heights.rbegin(), heights.rend());
        vector<string> res;
        for (int &h : heights) res.push_back(mp[h]);
        return res;
    }
};
