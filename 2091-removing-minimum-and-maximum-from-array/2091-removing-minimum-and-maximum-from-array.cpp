class Solution {
public:
    int minimumDeletions(vector<int>& A) {
        int a = max_element(begin(A), end(A)) - begin(A), b = min_element(begin(A), end(A)) - begin(A), N = A.size();
        if (a > b) swap(a, b);
        return min({ a + 1 + N - b, b + 1, N - a });
    }
};
