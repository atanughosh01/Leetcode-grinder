class Solution {
public:
    const int mod = 1e9 + 7;
    int sumSubarrayMins(vector<int> &arr) {
        stack<int> st;
        int ans = 0, n = arr.size();
        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || arr[st.top()] >= arr[i])) {
                int idx = st.top();
                st.pop();
                long long right = i < n ? i - idx : n - idx;
                long long left = st.empty() ? idx + 1 : idx - st.top();
                ans = (ans + left *right *arr[idx]) % mod;
            }
            st.push(i);
        }
        return ans;
    }
};
