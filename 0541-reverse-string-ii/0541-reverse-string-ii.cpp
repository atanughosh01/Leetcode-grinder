class Solution {
public:
    string reverseStr(string &s, int k) {
        int i = 0, n = s.size();
        while (i < n) {
            int j = min(i + k - 1, n - 1);
            int next_i = j + k + 1;
            while (i < j) {
                swap(s[i++], s[j--]);
            }
            i = next_i;
        }
        return s;
    }
};
