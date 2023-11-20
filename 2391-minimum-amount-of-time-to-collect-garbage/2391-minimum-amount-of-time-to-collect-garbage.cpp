class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int ans = 0, n = garbage.size(), m = travel.size();
        for (char c : "MPG") {
            int temp = 0, lastIdx = 0;
            for (int i = 0; i < n; i++) {
                for (char &x : garbage[i]) {
                    if (x == c) {
                        temp++;
                        lastIdx = i;
                    }
                }
                if (i < m) temp += travel[i];
            }
            for (int i = n - 2; i >= lastIdx; i--) {
                temp -= travel[i];
            }
            ans += temp;
        }
        return ans;
    }
};
