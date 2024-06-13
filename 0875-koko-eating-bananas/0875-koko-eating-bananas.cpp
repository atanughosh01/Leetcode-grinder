class Solution {
private:
    int hoursRequired(vector<int> &piles, int k) {
        if (k == 0) return INT_MAX;
        int h = 0;
        for (int &pile : piles) {
            h += (pile % k != 0) + (pile / k);
        }
        return h;
    }
public:
    int minEatingSpeed(vector<int> &piles, int H) {
        long long sum = 0;
        int mx = 0;
        for (int &pile : piles) {
            sum += pile;
            mx = max(mx, pile);
        }
        int l = sum / H, r = mx, ans = 0;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int ans = hoursRequired(piles, mid);
            if (ans > H) l = mid + 1;
            else r = mid;
        }
        return r;
    }
};
