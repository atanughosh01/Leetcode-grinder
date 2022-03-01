/*
    #define ull unsigned long long

    class Solution {
    private:
        int decimalToBinary(int N) {
            ull B_Number = 0;
            int cnt = 0;
            while (N != 0) {
                int rem = N % 2;
                ull c = pow(10, cnt);
                B_Number += rem * c;
                N /= 2;
                cnt++;
            }
            return B_Number;
        }

        int numOfSetBits(int N) {
            int dig, cnt = 0;
            while(N) {
                dig = N%10;
                if(dig == 1)
                    cnt++;
                N /= 10;
            }
            return cnt;
        }

    public:
        vector<int> countBits(int n) {
            int curr, count = 0;
            vector<int> res;
            for (int i=0; i<=n; i++) {
                curr = decimalToBinary(i);
                count = numOfSetBits(curr);
                res.emplace_back(count);
            }
            return res;
        }
    };
*/


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++) {
            int sum = 0, num = i;
            while(num) {
                sum += num%2;
                num = num/2;
            }
            ans.emplace_back(sum);
        }
        return ans;
    }
};
