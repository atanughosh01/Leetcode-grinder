class Solution {
public:
    bool canConstruct(string &ransomNote, string &magazine) {
        int ran[26] = {0}, mag[26] = {0};
        for (char x : ransomNote) ran[x - 'a']++;
        for (char y : magazine) mag[y - 'a']++;
        for (int i = 0; i < 26; i++) {
            if (ran[i] > mag[i]) {
                return false;
            }
        }
        return true;
    }
};
