class Solution {
private:
    int reversed(int n) {
        int rev = 0;  
        while (n) {     
            rev = rev * 10 + n % 10;    
            n /= 10;    
        }
        return rev;
    }
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i++) {
            if (i + reversed(i) == num) {
                return true;
            }
        }
        return false;
    }
};
