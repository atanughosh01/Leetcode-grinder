class Solution_1 {
public:
    void reverseString(vector<char> &s) {
        reverse(s.begin(), s.end());
    }
};


class Solution_2 {
public:
    void reverseString(vector<char> &s) {
        int n = s.size();
        for (int i = 0; i < n/2; i++) {
            swap(s[i], s[n - i - 1]);
        }
    }
};


class Solution {
public:
    void reverseString(vector<char> &s) {
        // for (int l = 0, r = s.size() - 1; l < r; ++l, --r) {
        //     if (s[l] != s[r]) {
        //         s[l] ^= s[r]; 
        //         s[r] ^= s[l];
        //         s[l] ^= s[r];
        //     }
        // }
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) {
                s[l] ^= s[r]; 
                s[r] ^= s[l];
                s[l] ^= s[r];
            }
            l++, r--;
        }
    }
};
