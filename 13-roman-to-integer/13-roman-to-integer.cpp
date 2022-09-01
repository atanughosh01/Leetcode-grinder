class Solution {
public:
    int romanToInt(string &roman) {
        unordered_map<char, int> T = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int integer = T[roman.back()];
        for (int i = roman.size() - 2; i >= 0; i--) {
            if (T[roman[i]] >= T[roman[i + 1]]) {
                integer += T[roman[i]];
            } else {
                integer -= T[roman[i]];
            }
        }
        return integer;
    }
};
