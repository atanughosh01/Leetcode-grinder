class Solution {
public:
    string getPermutation(int n, int k) {
        int pTable[10]{1};
        vector<char> numSet{'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        for (int i = 1; i <= 9; i++){
            pTable[i] = i * pTable[i - 1];
        }
        string res = "";
        while (n > 0) {
            int temp = (k - 1) / pTable[n - 1];
            res += numSet[temp];
            numSet.erase(numSet.begin() + temp);
            k -= temp * pTable[n - 1];
            n--;
        }
        return res;
    }
};
