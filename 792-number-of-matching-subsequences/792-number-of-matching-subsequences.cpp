class Solution_1 {
private:
    bool isSubSequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int j = 0;
        for (int i = 0; i < n && j < m; i++) {
            if (s1[j] == s2[i]) {
                j++;
            }
        }
        return (j == m);
    }
public:
    int numMatchingSubseq(string str, vector<string> &words) {
        int res = 0;
        for (string &word : words) {
            if (isSubSequence(word, str)) {
                res++;
            }
        }
        return res;
    }
};




class Solution {
public:
    int numMatchingSubseq(string str, vector<string> &words) {
        int res = 0;
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < str.size(); i++) {
            mp[str[i]].push_back(i);
        }
        for (int i = 0; i < words.size(); i++) {
            string curr = words[i];
            int latest = -1;
            for (int j = 0; j < curr.size(); j++) {
                auto it = upper_bound(mp[curr[j]].begin(), mp[curr[j]].end(), latest);
                if (it == mp[curr[j]].end()) break;
                latest = *it;
                if (j == curr.size() - 1) res++;
            }
        }
        return res;
    }
};
