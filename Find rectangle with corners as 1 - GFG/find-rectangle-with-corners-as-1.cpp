// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
#include <unordered_map>
#include <unordered_set>
using namespace std; 

 // } Driver Code Ends


// Problem : https://practice.geeksforgeeks.org/problems/253524a82f7b4561dc33ff637cd3b92c33d4f216/1


class Solution{
public:
    bool ValidCorner(const vector<vector<int> >& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==1){
                    int right,down;
                    for(right=j+1;right<c;right++){
                        if(matrix[i][right]==1){
                            for(down = i+1;down<r;down++){
                                if(matrix[down][right]==1){
                                    if(matrix[down][j]==1)return true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int row, col;
        cin>> row>> col;

        vector<vector<int> > matrix(row);
            
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        if (ob.ValidCorner(matrix)) 
            cout << "Yes\n"; 
        else
            cout << "No\n"; 
    }

    return 0;
} 


  // } Driver Code Ends