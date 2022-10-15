class Solution {
public:
    int compress(vector<char> &chars) {
        int idx = 0, n = chars.size(), cnt = 1;
        for (int i = 1; i <= n; i++) {
            if (i == n || chars[i] != chars[i - 1]) {
                chars[idx++] = chars[i - 1];
                if (cnt > 1) {
                    string str = to_string(cnt);
                    for (char &digit : str) {
                        chars[idx++] = digit;
                    }
                }
                cnt = 0;
            }
            cnt++;
        }        
        return idx;
    }
};
