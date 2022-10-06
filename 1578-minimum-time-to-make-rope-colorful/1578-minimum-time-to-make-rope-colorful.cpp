class Solution {
public:
    int minCost(string &colors, vector<int> &neededTime) {
        int n = colors.size(), res = 0, l = 0, r = 1;
        if (n == 1) return 0;
        int sum = neededTime[0], mx = neededTime[0];
        while (r <= n) {
            if (r < n && colors[r] == colors[l]) {
                sum += neededTime[r];
                mx = max(mx, neededTime[r]);
            } else {
                res += (sum - mx);
                if (r < n) {
                    l = r;
                    sum = neededTime[l];
                    mx = neededTime[l];
                }
            }
            r++;
        }
        return res;
    }
};
