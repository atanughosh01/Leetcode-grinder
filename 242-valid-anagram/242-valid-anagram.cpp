class Solution_1 {
public:
    bool isAnagram(string &s, string &t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};



class Solution {
public:
    bool isAnagram(string &s, string &t) {
        if (s.size() != t.size()) return false;
        int *freq = new int[26]{0};
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i]) {
                return false;
            }
        }
        return true;
    }
};
