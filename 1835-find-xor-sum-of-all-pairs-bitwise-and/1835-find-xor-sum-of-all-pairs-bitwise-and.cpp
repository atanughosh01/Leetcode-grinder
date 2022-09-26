class Solution {
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2) {
        int xora = 0, xorb = 0;
        for (int &a : arr1) xora ^= a;
        for (int &b: arr2) xorb ^= b;
        return xora & xorb;
    }
};
