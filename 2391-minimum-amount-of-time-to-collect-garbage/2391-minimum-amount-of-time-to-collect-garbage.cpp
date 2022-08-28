class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int ans = 0;
        for (char c : "MPG") {
            int temp = 0, lastIdx = 0;
            for (int i = 0; i < garbage.size(); i++) {
                for (char x : garbage[i]) {
                    if (x == c) {
                        temp++;
                        lastIdx = i;
                    }
                }
                if (i < travel.size()) temp += travel[i];
            }
            for (int i = garbage.size() - 2; i >= lastIdx; i--) {
                temp -= travel[i];
            }
            ans += temp;
        }
        return ans;
    }
};
