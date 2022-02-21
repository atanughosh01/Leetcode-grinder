class Solution {
public:
    int majorityElement(vector<int>& a) {
        int c(-1), cnt(0);
        for(auto n: a) {
            if (cnt == 0) c = n;
            cnt += (n == c) ? 1 : -1;
        }
        return c;
    }
};
