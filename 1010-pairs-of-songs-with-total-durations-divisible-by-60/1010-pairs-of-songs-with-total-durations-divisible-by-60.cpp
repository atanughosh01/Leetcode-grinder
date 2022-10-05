typedef long long ll;

class Solution_1 {
private:
    ll nextMultipleOfBase(ll n, ll base) {
        if (n<0) return 0;
        ll ans = 1;
        while (ans * base < n) ans += 1;
        if (ans*base == n) return base;
        return ans * base;
    }
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int n = time.size(), rem = 0, cnt =0;
        sort(time.begin(), time.end());
        unordered_map<int,int> ump;
        for(int i=0; i<n; i++) {
            rem = nextMultipleOfBase(time[i], 60);
            auto idx = ump.find(rem);
            if(idx != ump.end()) cnt++;
            ump[time[i]] = i;
        }
       return cnt;
    }
};


class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int mp[60]{0}, res = 0;
        for (int &x : time){
            int t = x % 60;
            int y = (60 - t) % 60;
            res += mp[y];
            mp[t]++;
        }
        return res;
    }
};
