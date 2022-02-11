/*

// Logically correct but TLE solution

class Solution {
private:
    string srt(string s) {
        string a = s;
        sort(a.begin(), a.end());
        return a;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int m = (int)s1.size();
        int n = (int)s2.size();
        for(int i=-1; i<n-m; ++i) {
            string sub = s2.substr(i+1, m);
            if(srt(s1) == srt(sub))
                return true;
        }
        return false;
    }
};

*/



class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int mp[26] = {0};
        for(char c : s1) mp[c - 'a']++;
        int j = 0, i = 0, count_chars = s1.size();
        while(j < s2.size()){
            if(mp[s2[j++]-'a']-- > 0)
                count_chars--;
            if(count_chars == 0)
                return true;
            if(j-i == s1.size() and mp[s2[(i++)]-'a']++ >= 0)
                count_chars++;
        }
        return false;
    }
};
