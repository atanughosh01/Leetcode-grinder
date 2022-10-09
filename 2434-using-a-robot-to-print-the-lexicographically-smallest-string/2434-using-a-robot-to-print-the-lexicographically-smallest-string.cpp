class Solution {
public:
    string robotWithString(string &s) {
        int cnt[26] = {0};
        for (char &c : s)  cnt[c - 'a']++;
        string t = "", ans = "";
        for (char &c : s) {
            int small = -1;
            for (int j = 0; j <= c - 'a'; j++) {
                if (cnt[j] > 0) {
                    small = j;
                    break;
                }
            }
            cnt[c - 'a']--;
            while (!t.empty() && t.back() - 'a' <= small) {
                ans += t.back();
                t.pop_back();
            }
            (small < c - 'a') ? t += c : ans += c;
        }
        reverse(t.begin(), t.end());
        ans += t;
        return ans;
    }
};
