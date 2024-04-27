class Solution {
private:
    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int n = s.size();
        if (n < 3) return true;
        int l = 0, r = n - 1;
        while(l < n && r >= 0 && s[l] == s[r] && l < r) {
            l++;
            r--;
        }
        if (r - l < 2) return true;
        return isPalindrome(s.substr(l + 1, r - l)) || isPalindrome(s.substr(l, r - l));
    }
};
