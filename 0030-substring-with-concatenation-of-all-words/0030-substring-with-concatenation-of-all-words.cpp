class Solution_1 {
public:
    vector<int> findSubstring(string &s, vector<string> &words) {
        int n = s.size(), num = words.size();
        if (n == 0 || num == 0) return {};
        unordered_map<string, int> counts;
        vector<int> indexes;
        for (string &word : words) counts[word]++;
        int len = words[0].size();
        for (int i = 0; i < n - num * len + 1; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < num; j++) {
                string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) {
                    seen[word]++;
                    if (seen[word] > counts[word]) break;
                } else break;
            }
            if (j == num) indexes.push_back(i);
        }
        return indexes;
    }
};



class Solution {
   public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        int n = words.size(), m = words[0].size(), len = s.size();
        if (s.size() < m * n) return res;
        unordered_map<string, int> freq;
        for (string &word : words) freq[word]++;
        for (int i = 0; i <= len - m * n; i++) {
            unordered_map<string, int> mp = freq;
            int j;
            for (j = 0; j < len; j++) {
                string temp = s.substr(i + j * m, m);
                if (!mp[temp]) break;
                else mp[temp]--;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};
