/*
    // Time : O(m*m*n), Space : O(m + n); BRUTEFORCE;
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
*/


class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = (int)queries.size(), temp;
        vector<int> p(m+1);
        p[0] = 0;
        for (int i=1; i<=m; i++) {
            p[i] = i-1;
        }
        for (int j=0; j<n; j++) {
            temp = p[queries[j]];
            for(int i=1; i<=m; i++)
                if(p[i] <= temp) {
                    p[i]++;
                }
            p[queries[j]] = 0;
            queries[j] = temp;
        }
        return queries;
    }
};
