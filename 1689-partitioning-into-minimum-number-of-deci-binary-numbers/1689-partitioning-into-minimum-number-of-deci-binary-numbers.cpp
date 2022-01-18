/*
class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char c : n)
            ans = max(ans, c-'0');
        return ans;
    }
};
*/
    
class Solution {
public:
    int minPartitions(string n) {
        sort(n.begin(), n.end());
        return n[n.size()-1] - '0';
    }
};
