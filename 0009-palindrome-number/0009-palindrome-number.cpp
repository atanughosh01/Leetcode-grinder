class Solution_1 {
public:
    bool isPalindrome(int x) {
        unsigned int orig = x, back_x = 0;
        while (x > 0) {
            back_x = (back_x * 10) + (x % 10);
            x /= 10;
        }
        return (orig == back_x);
        
    }
};


class Solution_2 {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long long reversed = 0, temp = x;
        while (temp) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }

        return (reversed == x);
    }
};


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return (x == reversed) || (x == reversed / 10);
    }
};
