/*
    class Solution {
    public:
        string removeDuplicateLetters(string s) {
            string res="";
            int lastPos[26] = {};
            bool added[26] = {};
            for (int i = 0; i < s.size(); i++) {
                lastPos[s[i] - 'a'] = i;
            }
            for (int i = 0; i < s.size(); i++) {
                if (added[s[i] - 'a']) continue;
                while ( !res.empty() && res.back() > s[i] && lastPos[res.back() - 'a'] > i) {
                    added[res.back() - 'a'] = false;
                    res.pop_back();
                }
                res.push_back(s[i]);
                added[s[i] - 'a'] = true;
            }
            return res;
        }
    };
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(26,0)  , vis(26,0);
        string res = "";
        int n = s.size();
        for(int i = 0; i<n; ++i) {
            cnt[s[i] - 'a']++;
        }
        for(int i = 0; i<n; ++i) {
            cnt[s[i] - 'a']--;
            if(!vis[s[i]- 'a']) {
                while(res.size() > 0 && res.back() > s[i] && cnt[res.back() - 'a'] > 0) {
                    vis[res.back() - 'a'] = 0;
                    res.pop_back();
                }
                res += s[i];
                vis[s[i] - 'a'] = 1;
            }
        }
        return res;
    }
};
