// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// ranges[i][0] is the start of ith range
// ranges[i][1] is the end of ith range



// Problem : https://practice.geeksforgeeks.org/problems/87ecf96cfd61e511c697c8c94d21c5de7f471fcb/1



class Solution{
public:
    static bool fun(vector<int>& v1,vector<int>& v2){
       return v1[1]<v2[1];
    }
    int max_non_overlapping( vector<vector<int>>& ranges ) {
       sort(ranges.begin(), ranges.end(), fun);
       int c=1, d=ranges[0][1];
       for(int i=1; i<ranges.size(); i++){
           if(ranges[i][0]>=d){
               c++;
               d=ranges[i][1];
           }
       }
       return c;
   }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		vector< vector<int> > v(n,vector<int>(2));
		for(int i=0; i<n; i++)
			cin>> v[i][0] >> v[i][1];
			
        Solution ob;
		cout<< ob.max_non_overlapping(v) << endl;
	}
	return 1;
}

  // } Driver Code Ends