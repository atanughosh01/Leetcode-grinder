// class Solution {
// public:
//     string repeatLimitedString(string s, int lim) {
//         sort(s.rbegin(), s.rend());
//         string s2 = "";
//         int cnt = 1;
//         for(int i=1; i<s.size(); ++i) {
//             if(s[i] == s[i-1]) {
//                 cnt++;
//                 if(cnt >= lim) {
//                     s2 += s[i];
//                     s.erase(s.begin() + i);
//                     cnt--;
//                 }
//             } else {
//                 cnt = 1;
//             }
//         }
//         return (s+s2);
//     }
// };


class Solution {
public:
   string repeatLimitedString(string s, int lim) {
        string res;
        int cnt[26] = {};
        for (auto ch : s)
            ++cnt[ch - 'a'];
        for (int i = 25, j = 26; j >= 0; ) {
            while (i >= 0 && cnt[i] == 0)
                --i;
            if (i >= 0) {
                res += string(min(lim - (i == j), cnt[i]), 'a' + i);
                cnt[i] -= min(lim - (i == j), cnt[i]);
            }
            j = min(i - 1, j);
            while (j >= 0 && cnt[j] == 0)
                --j;        
            if (j >=0) {
                res += string(1, 'a' + j);
                --cnt[j];
            }
        }
        return res;
    }
};
