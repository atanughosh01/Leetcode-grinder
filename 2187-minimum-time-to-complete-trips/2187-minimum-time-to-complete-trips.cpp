class Solution {
private:
     bool check(vector<int> &arr, int lim, long long x) {
        long long sum = 0;
        for (int &num : arr) sum += x / num;
        return sum >= lim;
    };
public:
    long long minimumTime(vector<int> &times, int totalTrips) {
        int minTime = *min_element(times.begin(), times.end());
        long long lowTime = 0, mid = 0;
        long long highTime = totalTrips * 1ll * minTime;
        while (lowTime < highTime) {
            mid = lowTime + (highTime - lowTime) / 2;
            if (!check(times, totalTrips, mid)) {
                lowTime = mid + 1;
            } else {
                highTime = mid;
            }
        }
        return lowTime;
    }
};
