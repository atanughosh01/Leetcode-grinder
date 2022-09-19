// O(n * log(n)) Time | O(1) Space
class Solution_1 {
public:
    bool canMakeArithmeticProgression(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int d = arr[1] - arr[0];
        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] != d) {
                return false;
            }
        }
        return true;
    }
};


// O(n) Time | O(1) Space
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int> &arr) {
        int n = arr.size();
        int mn = INT_MAX, mx = INT_MIN;
        for (int &x : arr) {
            mn = min(mn, x);
            mx = max(mx, x);
        }
        if (mx == mn) return true;
        if ((mx - mn) % (n - 1) != 0) return false;
        int d = (mx - mn) / (n - 1), i = 0;
        while (i < n) {
            if (arr[i] == mn + i * d) i++;
            else if ((arr[i] - mn) % d != 0) return false;
            else {
                int pos = (arr[i] - mn) / d;
                if (pos < i || arr[pos] == arr[i]) return false;
                swap(arr[i], arr[pos]);
            }
        }
        return true;
    }
};
