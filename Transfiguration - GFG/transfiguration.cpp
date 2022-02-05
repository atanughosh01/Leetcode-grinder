// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/b6b3297ccfb1ad5f66a9c2b92979170417adf114/1

class Solution{
public:
    int transfigure (string A, string B) {
        int freq[256];
    	memset(freq,0,sizeof(freq));
    	
    	for(char ch:A)
    	freq[ch-'0']++;
    	for(char ch:B)
    	freq[ch-'0']--;
    	for(int x:freq)
    	{
    	    if(x!=0)
    	    return -1;
    	}
    	
    	int i=A.length()-1,j=B.length()-1,count=0;
    	while(i>=0 && j>=0)
    	{
    	    if(A[i]==B[j])
    	    {
    	        i--; j--;
    	    }
    	    else
    	    {
    	        count++;
    	        i--;
    	    }
    	}
    	return count;
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends