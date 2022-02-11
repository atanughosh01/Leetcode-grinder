class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        if(res<INT_MIN or res>INT_MAX)
            return 0;
        else
            return res;
    }
};
