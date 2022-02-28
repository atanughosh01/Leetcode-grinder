/*
    // O(N*N) Brute Force
    class Solution {
    public:
        vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
            int len = (int)s.size(), count = 0;
            vector<int> ans(len);
              for(int i = 0; i < len; i++){
                int cx = startPos[0];
                int cy = startPos[1];
                int count = 0;
                for(int j = i; j < len; j++){
                    char ch = s[j];
                    if(ch == 'R' && cy+1 < n){
                        cy++;
                        count++;
                    }
                    else if(ch == 'D' && cx+1 < n){
                        cx++;
                        count++;
                    }
                    else if(ch == 'L' && cy-1 >= 0){
                        cy--;
                        count++;
                    }
                    else if(ch == 'U' && cx-1 >= 0){
                        cx--;
                        count++;
                    }
                    else {
                        break;
                    }
                }
                ans[i] = count;
            }
            return ans;
        }
    };
*/


// O(N) Optimised
class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& st, string s) {
        int m = s.size(), h = m + n, v = m + n;
        vector<int> hor((m + n) * 2, m), ver((m + n) * 2, m), res(m);
        for (int i = m - 1; i >= 0; --i) {
            hor[h] = ver[v] = i;
            h += s[i] == 'L' ? 1 : s[i] == 'R' ? -1 : 0;
            v += s[i] == 'U' ? 1 : s[i] == 'D' ? -1 : 0;
            res[i] = min({m, hor[h - st[1] - 1], hor[h - st[1] + n], ver[v - st[0] - 1], ver[v - st[0] + n]}) - i;
        }
        return res;
    }
};
