#define ll long long
class Solution {
public:
    bool isPossible(vector<int> &target) {
        ll sum = 0;
        priority_queue<ll> pq;
        for (int num : target) {
            sum += (ll)num;
            pq.push((ll)num);
        }
        while (pq.top() != 1) {
            sum -= pq.top();
            if (sum == 0 || sum >= pq.top()) return false;
            ll old = pq.top() % sum;
            if (sum != 1 && old == 0) return false;
            pq.pop();
            pq.push(old);
            sum += old;
        }
        return true;
    }
};
