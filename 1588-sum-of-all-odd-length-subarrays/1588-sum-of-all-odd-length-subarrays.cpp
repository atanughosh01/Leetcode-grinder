// Bruteforce | Time O(n^3) | Space O(1) | n = arr.length
class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if ((j - i) % 2 == 0) {
                    for (int k = i; k <= j; k++) {
                        res += arr[k];
                    }
                }
            }
        }
        return res;
    }
};
