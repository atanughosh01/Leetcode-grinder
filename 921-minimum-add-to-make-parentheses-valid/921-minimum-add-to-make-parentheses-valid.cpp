class Solution {
public:
    int minAddToMakeValid(string s) {
        int res = 0, balance = 0;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(') balance++;
            else if (s[i] == ')') balance--;
            if (balance == -1) {
                res++;
                balance++;
            }
        }
        res += balance;
        return res;
    }
};
