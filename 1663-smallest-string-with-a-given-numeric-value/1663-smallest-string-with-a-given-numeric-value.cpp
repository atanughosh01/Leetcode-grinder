/*
    class Solution {
    public:
        string getSmallestString(int n, int k) {
            string s(n,'a');
            k -= n;
            for(int i=n-1; i>=0; i--) {
                if(k==0) break;
                else if(k < 25) {
                    s[i] = (char)('a' + k);
                    k = 0;
                } else {
                    s[i] = (char)('a' + 25);
                    k -= 25;
                }
            }
            return s;
        }
    };
*/


class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        int ptr = n-1;
        while (k > 0) {
            s[ptr--] += min(k, 25);
            k -= min(k, 25);
        }
        return s;
    }
};
