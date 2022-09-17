class Solution {
public:
    int subtractProductAndSum(int n) {
        long long sum = 0, pdt = 1;
        while (n) {
            sum += n % 10;
            pdt *= n % 10;
            n /= 10;
        }
        return pdt - sum;
    }
};
