class Solution {
private:
    int digSum(int n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int countEven(int num) {
        int cnt = 0;
        for(int i=1; i<=num; ++i) {
            if(digSum(i)%2 == 0)
                cnt++;
        }
        return cnt;
    }
};
