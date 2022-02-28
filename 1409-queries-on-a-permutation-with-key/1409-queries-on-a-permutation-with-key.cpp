class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = (int)queries.size();
        vector<int> ans, p(m);
        for (int i=0; i<m; i++) {
            p[i] = i+1;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (p[j] == queries[i]) {
                    ans.emplace_back(j);
                    p.insert(p.begin(), p[j]);
                    p.erase(p.begin()+j+1);
                    break;
                }
            }
        }
        return ans;
    }
};
