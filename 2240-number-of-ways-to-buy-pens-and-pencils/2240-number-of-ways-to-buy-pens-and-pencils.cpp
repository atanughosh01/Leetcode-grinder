#define ll long long

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        ll ans = 0;
        if (cost2 < cost1) swap(cost1, cost2);
        for (int i = 0; i <= total; i += cost1) {
            ans += (total - i)/cost2 + 1;
        }
        return ans;
    }
};
