// Bruteforce | Time O(n^3) | Space O(1) | n = arr.length
class Solution_1 {
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



// Slightly Optimized | Time O(n^2) | Space O(1) | n = arr.length
class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size(), res = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += arr[j];
                if ((j - i) % 2 == 0) {
                    res += sum;
                }
            }
        }
        return res;
    }
};
