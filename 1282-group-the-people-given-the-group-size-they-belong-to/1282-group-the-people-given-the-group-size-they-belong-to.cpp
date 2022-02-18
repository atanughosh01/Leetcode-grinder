/*
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& gz) {
      vector<vector<int>> res, groups(gz.size() + 1);
      for (auto i = 0; i < gz.size(); ++i) {
        groups[gz[i]].push_back(i);
        if (groups[gz[i]].size() == gz[i]) {
          res.push_back({});
          swap(res.back(), groups[gz[i]]);
        }
      }
      return res;
    }
};

*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> m;
        for(int i=0; i<g.size(); i++) {
			m[g[i]].push_back(i);
			if(m[g[i]].size()==g[i]) {
                ans.push_back(m[g[i]]);
                m[g[i]].clear();
            }
        }
        return ans; 
    }
};
