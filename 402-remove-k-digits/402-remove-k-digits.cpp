class Solution_1 {
public:
    string removeKdigits(string &num, int k) {
        while (k--) {  
            int n = num.size(), idx = 0;
            while (idx+1<n && num[idx] <= num[idx+1]) idx++;
            num.erase(idx, 1);
        }
        int cnt = 0;
        while (cnt<num.size()-1 && num[cnt]=='0') cnt++;
        num.erase(0, cnt);
        if (num=="") return "0";
        return num;
    }
};


class Solution {
public:
    string removeKdigits(string num, int k) {
        string res = "";
        int n = num.size(), keep = n - k;
        for (int i=0; i<n; i++) {
            while (res.size()>0 && res.back()>num[i] && k>0) {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        res.erase(keep, string::npos);
        int cnt = 0;
        while (cnt<res.size()-1 && res[cnt]=='0') cnt++;
        res.erase(0, cnt);
        if (res=="") return "0";
        return res;
    }
};
