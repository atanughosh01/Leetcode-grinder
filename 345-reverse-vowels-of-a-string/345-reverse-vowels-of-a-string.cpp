class Solution_1 {
private:
    bool isVowel(char &c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
public:
    string reverseVowels(string &s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            while (l < r && !isVowel(s[l])) l++;
            while (l < r && !isVowel(s[r])) r--;
            if (l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};


class Solution {
private:
    bool isVowel(char &c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || 
            c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
public:
    string reverseVowels(string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (isVowel(s[l]) && isVowel(s[r])) {
                swap(s[l++], s[r--]);
            }
            else if (isVowel(s[l])) r--;
            else if (isVowel(s[r])) l++;
            else l++, r--;
        }
        return s;
    }
};
