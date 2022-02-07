/*
class Solution { 
public:
    char findTheDifference(string s, string t) {
        int n = (int)s.size();
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<n; ++i) {
            if(s[i] != t[i])
                return t[i];
        }
        return t[n];
    }
};

*/


// XOR
class Solution {
public:
    char findTheDifference(string s, string t) {
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};
