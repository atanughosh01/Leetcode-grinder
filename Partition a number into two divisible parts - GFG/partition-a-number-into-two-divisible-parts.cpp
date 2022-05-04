// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/partition-a-number-into-two-divisible-parts3605/1



class Solution {   
public:
    string stringPartition(string S, int a, int b) {
        for (int i = 1; i < S.size(); ++i) {
            string part1 = S.substr(0, i);
            int num1 = stoi(part1);
            if (num1%a != 0)continue;
            string part2 = S.substr(i);
            int num2 = stoi(part2);
            if (num2 % b == 0)
                return (part1 + " " + part2);
        }
        return "-1";
    }
};



// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
}   // } Driver Code Ends