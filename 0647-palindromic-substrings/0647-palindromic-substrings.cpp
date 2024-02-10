class Solution {
public:
    int countSubstrings(string &S) {
        int len = S.size(), res = 0;
        for (int i = 0; i < len; i++) {
            int j = i - 1, k = i;
            while (k < len - 1 && S[k] == S[k+1]) k++;
            res += (k - j) * (k - j + 1) / 2, i = k++;
            while (~j && k < len && S[k++] == S[j--]) res++;
        }
        return res;
    }
};
