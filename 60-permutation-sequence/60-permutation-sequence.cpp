class Solution {
private:
    vector<int> fact;
    void findfact(int n) {
        fact = vector<int>(n, 1);
        if (n == 1) return;
        for (int i = 2; i < n; i++) {
            fact[i] = i * fact[i - 1];
        }
    }
public:
    string getPermutation(int N, int K) {
        int n = N - 1, k = K - 1, nt, kt;
        findfact(N);
        vector<int> num(N, 0);
        for (int i = 0; i < N; i++) {
            num[i] = i + 1;
        }
        vector<int>::iterator itr;
        string ans = "";
        while (n >= 0) {
            nt = k / fact[n];
            kt = k % fact[n];
            ans += (num[nt] + '0');
            itr = num.begin();
            num.erase(itr + nt);
            n--;
            k = kt;
        }
        return ans;
    }
};
