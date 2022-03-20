class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> it;
        it = {INT_MIN};
        int res = 0;
        for (int k : nums) {
            if (k != it.back())
                it.emplace_back(k);
        }
        for (int i=2; i<it.size()-1; i++) {
            if (it[i-1] > it[i] && it[i+1] > it[i]) res++;
            if (it[i-1] < it[i] && it[i+1] < it[i]) res++;
        }
        return res;
    }
};
