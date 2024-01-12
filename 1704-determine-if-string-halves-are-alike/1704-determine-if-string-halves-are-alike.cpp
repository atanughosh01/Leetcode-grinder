class Solution {
private:
    int countVowel(int start, int end, string &s) {
        const string vowels = "aeiouAEIOU";
        int ans = 0;
        for (int i = start; i < end; i++) {
            if (vowels.find(s[i]) != string::npos) {
                ans++;
            }
        }
        return ans;
    }
public:
    bool halvesAreAlike(string &s) {
        int n = s.size();
        return countVowel(0, n / 2, s) == countVowel(n / 2, n, s);
    }
};
