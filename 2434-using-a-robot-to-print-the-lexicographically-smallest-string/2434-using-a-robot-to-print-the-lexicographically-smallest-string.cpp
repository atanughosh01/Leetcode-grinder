class Solution {
public:
    string robotWithString(string &s) {
        int cnt[26]{0};
        string t = "", ans = "";
        for (char &c : s)  cnt[c - 'a']++;
        for (char &c : s) {
            int small = 0;
            t += c;
            cnt[c - 'a']--;
            while (small < 26 && cnt[small] == 0) small++;
            while (!t.empty() && t.back() - 'a' <= small) {
                ans += t.back();
                t.pop_back();
            }
        }
        return ans;
    }
};
