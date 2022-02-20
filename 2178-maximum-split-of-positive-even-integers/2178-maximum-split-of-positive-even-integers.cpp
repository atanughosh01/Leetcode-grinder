/*
    class Solution {
    public:
        vector<long long> maximumEvenSplit(long long num) {
            vector<long long> arr = {};
            if(num%2)
                return arr;
            int con = 0;
            while(true) {
               con += 2;
               num -= con;
                if(num >= con+2)
                    arr.push_back(con);
                else{
                    arr.push_back(num + con);
                    break;
                }
           }
            return arr;
        }
    };


    // Time: O(sqrt(N))
    // Space: O(sqrt(N))
    class Solution {
    public:
        vector<long long> maximumEvenSplit(long long s) {
            if (s % 2) return {};
            vector<long long> ans;
            function<bool(long, long)>dfs = [&](long i, long target) {
                if (target == 0) return true;
                if (target < i) return false;
                ans.push_back(i);
                if (dfs(i + 2, target - i)) return true; // use `i`
                ans.pop_back();
                return dfs(i + 2, target); // skip `i`
            };
            dfs(2, s);
            return ans;
        }
    };
*/


// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    vector<long long> maximumEvenSplit(long long s) {
        if (s % 2) return {};
        vector<long long> ans;
        for (int i = 2; s - i >= i + 2; i += 2) {
            ans.push_back(i);
            s -= i;
        }
        ans.push_back(s);
        return ans;
    }
};
