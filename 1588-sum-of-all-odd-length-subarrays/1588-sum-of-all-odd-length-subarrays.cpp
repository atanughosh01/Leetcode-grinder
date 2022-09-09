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
class Solution_2 {
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



// Optimal | Time O(n) | Space O(1) | n = arr.length
class Solution_3 {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int start_i = n - i;                // number of sub-arrays starts with arr[i]
			int end_i = i + 1;                  // number of sub-arrays ends with arr[i]
			int total = start_i * end_i;        // total sub-arrays containing arr[i]
			res += arr[i] * ceil(total / 2.0);  // contribution of arr[i] in odd length sub-arrays
        }
        return res;
    }
};



// Simply
class Solution_4 {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; i++) {
			res += arr[i] * ceil((n - i) * (i + 1) / 2.0);
        }
        return res;
    }
};



// Even Better
class Solution {
public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size(), res = 0;
        for (int i = 0; i < n; i++) {
			res += arr[i] * (((n - i) * (i + 1) + 1) / 2);
        }
        return res;
    }
};
