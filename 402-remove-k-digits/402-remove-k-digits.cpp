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
