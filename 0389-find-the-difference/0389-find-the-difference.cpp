class Solution_1 { 
public:
    char findTheDifference(string &s, string &t) {
        int n = s.size();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                return t[i];
            }
        }
        return t[n];
    }
};


// XOR
class Solution_2 {
public:
    char findTheDifference(string &s, string &t) {
        char r = 0;
        for (char &c : s) r ^=c;
        for (char &c : t) r ^=c;
        return r;
    }
};


// ASCII
class Solution {
public:
    char findTheDifference(string &s, string &t) {
        int ans = 0;
        for (auto &x : t) ans += x;
        for (auto &x : s) ans -= x;
        return char(ans);
    }
};
