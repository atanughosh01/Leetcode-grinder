class Solution {
public:
    int titleToNumber(string col) {
        int a[26], res = 0;
        for (int i=0; i<26; i++) {
            a[i] = i+1;
        }
        for (char x : col) {
            res *= 26;
            res += a[(x-'0')-17];
        }
        return res;
    }
};
