class Solution {
public:
    long long numberOfWays(string a) {
        int n = (int)a.size(), cz = 0, co = 0;
        vector<int> lz(n), rz(n), lo(n), ro(n);
        for(int i=0; i<n; i++) {
            if(a[i]=='0') cz++;
            else co++;
            lo[i] = co;
            lz[i] = cz;
        }
        co = cz = 0;
        for(int i=n-1; i>=0; i--) {
            if(a[i]=='0') cz++;
            else co++;
            ro[i] = co;
            rz[i] = cz;
        }
        long long c = 0;
        for(int i=0; i<n; i++) {
            if(a[i]=='0') c += lo[i] * ro[i];
            else c += lz[i] * rz[i];
        }
        return c;
    }
};
