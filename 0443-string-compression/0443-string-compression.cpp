class Solution {
public:
    int compress(vector<char> &chars) {
        int idx = 0, n = chars.size();
        for (int j = 1, count = 1; j <= n; j++, count++) {
            if (j == n || chars[j] != chars[j - 1]) {
                chars[idx++] = chars[j - 1];
                if (count >= 2) {
                    string str = to_string(count);
                    for (char &digit : str) {
                        chars[idx++] = digit;
                    }
                }
                count = 0;
            }
        }
        return idx;
    }
};
