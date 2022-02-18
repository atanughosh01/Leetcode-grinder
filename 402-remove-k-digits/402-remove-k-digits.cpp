/*

class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k--) {  
            int n = (int)num.size();
            int idx = 0;
            while(idx+1<n and num[idx]<=num[idx+1])
                idx++;
            num.erase(idx, 1);
        }
        int cnt = 0;
        while (cnt<(int)num.size()-1 and num[cnt]=='0')
            cnt++;
        num.erase(0, cnt);
        
        if(num=="")
            return "0";
        
        return num;
    }
};

*/


class Solution {
public:
    string removeKdigits(string num, int k) {
        
        string res;
        int n = (int)num.size();
        int keep = n - k;
        for (int i=0; i<n; i++) {
            while ((int)res.size()>0 and res.back()>num[i] and k>0) {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        res.erase(keep, string::npos);
        
        int cnt = 0;
        while (cnt<(int)res.size()-1 and res[cnt]=='0')
            cnt++;
        res.erase(0, cnt);
        
        if(res=="")
            return "0";
        
        return res;
    }
};
