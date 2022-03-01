// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/1df2447c003940512562d766cf0583bbdc7a75ed/1



class Solution{
private:
    // Utility Function to convert a integer to string
    string numberToString(int N){
        string ans = "";
        while(N){
            int dig = N % 10;
            string a = to_string(dig);
            ans = a + ans;
            N = N/10;
        }
        return ans;
    }

public:
    //This function counts number of pairs in our vector
    long long countPairs(int N, int X, vector<int> numbers){
        //We make unordered map of string and convert our elements of numbers vector into string and store them as key of our map and increment their count(value)
        unordered_map<string, int> mp;
        for(int i = 0; i < N; i++){
            mp[numberToString(numbers[i])]++;
        }
        //Converting our X to string and finding out two substrings of length varying from 1 to size - 1
        string mainNumber = numberToString(X);
        int cnt = 0;
        for(int i = 1; i < mainNumber.size(); i++){
            //Fining our s1 and s2
            string s1 = mainNumber.substr(0, i);
            string s2 = mainNumber.substr(i);
            //if s1 and s2 are different and there are present in our map then multiply it by their count value and add them in our totalCount
            if(s1 != s2){
                if(mp.count(s1) && mp.count(s2)){
                    cnt += mp[s1]*mp[s2];
                }
            }
            //Else if they are same (like 1212 have 12 12), then only add in count if s1 has come more than once
            else{
                cnt += mp[s1]*(mp[s1] - 1);
            }
        }
        //return the final count
        return cnt;
    }
}; 



// { Driver Code Starts.
int main() 
{ 
    int t;cin>>t;
    while(t--)
    {
        int N,X;
        cin>>N>>X;
        vector<int> numbers(N);
        for(int i=0;i<N;i++)
            cin>>numbers[i];
        Solution ob;
        long long ans = ob.countPairs(N, X, numbers);
        cout<<ans<<endl;
        
    }

    return 0; 
}  // } Driver Code Ends