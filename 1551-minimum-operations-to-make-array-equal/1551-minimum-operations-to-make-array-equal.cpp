/*
    class Solution {
    public:
        int minOperations(int n) {
            int opr = 0;
            for (int i=0; i<n/2; i++) {
                opr += (n -(2*i+1));
            }
            return opr;
        }
    };
*/

class Solution {
public:
    int minOperations(int n) {
        return (n*n / 4);
    }
};
