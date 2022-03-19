class Solution {
public:
    bool divideArray(vector<int>& a) {
        int n = (int)a.size();
        sort(a.begin(), a.end());
        for(int i=0; i<n-1; i+=2) {
            if(a[i] != a[i+1])
                return false;
        }
        return true;
    }
};
