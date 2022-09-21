class Solution {
public:
    string frequencySort(string &s) {
        int freq[256]{0};
        for (const char &c : s) freq[c]++;
        sort(s.begin(), s.end(), [&](const char &a, const char &b) {
            return freq[a] == freq[b] ? a < b : freq[a] > freq[b];
        });
        return s;
    }
};
