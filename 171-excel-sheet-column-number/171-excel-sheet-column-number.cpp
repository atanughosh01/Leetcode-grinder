/*
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
*/


class Solution {
public:
    int titleToNumber(string col) {
        int res = 0;
        for (char x : col) {
            int ch = x - 'A' + 1;
            res *= 26;
            res += ch;
        }
        return res;
    }
};
