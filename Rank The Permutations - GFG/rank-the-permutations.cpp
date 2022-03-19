// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/rank-the-permutations2229/1



class Solution{
private:
    long long perm(int n){
        long long ans = 1;
        if(n==0 || n==1) return 1ll;
        else{
            for(int i=1; i<=n; i++)
            ans *= (i*1ll);
        }
        return ans;
    }
public:
    long long findRank(string str) {
        int len = (int)str.size();
        long long ans=0;
        for(int i=0; i<len; i++){
            int less = 0;
            for(int j=i+1; j<len; j++){
                if(str[j] < str[i])
                    less++;
            }
            ans += less * perm(len-1-i);
        }
        return ans+1;
    }
};



// { Driver Code Starts.
int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  // } Driver Code Ends