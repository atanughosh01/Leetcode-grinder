class Solution {
private:
    int reversed(int n) {
        int r = 0;
        while (n) {
            r = r * 10 + n % 10;
            n /= 10;
        }
        return r;
    }
public:
    int countDistinctIntegers(vector<int> &nums) {
        unordered_set<int> st;
        for (int &num : nums) {
            st.insert(num);
            int rev = reversed(num);
            st.insert(rev);
        }
        return st.size();
    }
};
