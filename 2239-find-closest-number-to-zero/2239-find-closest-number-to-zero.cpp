#define ll long long
#define inf ((ll)(2e18))

class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int n = nums.size();
        ll mn = inf, mx = -inf;
        for (int i=0; i<n; i++) {
            if (nums[i] > 0) mn = min(mn, (ll)nums[i]);
            else mx = max(mx, (ll)nums[i]);
        }
        if (abs(mn) <= abs(mx)) return (int)mn;
        else return (int)mx;
    }
};
