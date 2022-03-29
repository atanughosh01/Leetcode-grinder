/*
    class Solution {
    public:
        int wateringPlants(vector<int> &p, int capacity) {
            int res = 0, can = capacity;
            for (int i = 0; i < p.size(); ++i) {
                if (can < p[i]) {
                    res += i * 2;
                    can = capacity;
                }
                can -= p[i];
            }
            return res + p.size();
        }
    };
*/


class Solution {
public:
    int wateringPlants(vector<int>& P, int C) {
        int ans = 0, cur = C;
        for(int i = 0; i < size(P); i++) {
            if(P[i] > cur) {      // water available less than whats needed
                cur = C;
                ans += 2*i;
            }
            ans++;                // move to current index
            cur -= P[i];          // subtract available water from can
        }
        return ans;
    }
};
