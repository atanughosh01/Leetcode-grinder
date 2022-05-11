// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/largest-number-with-given-sum-1587115620/1



class Solution {
   public:
    string largestNumber(int n, int sum) {
        if (9 * n < sum)
            return "-1";
        string s = "";
        while (n--) {
            if (sum >= 9) {
                s += "9";
                sum -= 9;
            } else if (sum > 0) {
                s += to_string(sum);
                sum = 0;
            } else {
                s += "0";
            }
        }
        return s;
    }
};




// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends