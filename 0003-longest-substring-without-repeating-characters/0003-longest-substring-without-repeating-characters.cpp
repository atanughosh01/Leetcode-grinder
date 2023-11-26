class Solution_1 {
public:
    int lengthOfLongestSubstring(string &s) {
        unordered_map<char, int> m;
        int max_len = -1, len = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]] = 0;
            len = 0;
            for (int j = i; j < s.size(); j++) {
                m[s[j]]++;
                if (m[s[j]] == 1) len++;
                else if (m[s[j]] > 1) {
                    max_len = max(max_len, len);
                    break;
                }
            }
        }
        return max_len;
    }
};



// T L E   Solution
class Solution_2 {
private:
    bool checkRepetition(string &s, int start, int end) {
        int chars[128] = {0};
        for (int i = start; i <= end; i++) {
            char c = s[i];
            chars[c]++;
            if (chars[c] > 1) {
                return false;
            }
        }
        return true;
    }
public:
    int lengthOfLongestSubstring(string &s) {
        int n = s.length(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (checkRepetition(s, i, j)) {
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};



class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        unordered_map<char, int> freq;
        int start = -1, max_len = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (freq.count(s[i])) {
                start = max(start, freq[s[i]]);
            }
            freq[s[i]] = i;
            max_len = max(max_len, i-start);
        }
        return max_len;
    }
};
