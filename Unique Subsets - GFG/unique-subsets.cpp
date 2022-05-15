// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



// Problem : https://practice.geeksforgeeks.org/problems/subsets-1587115621/1



class Solution {
private:
    void makeSubsets(set<vector<int>> &ans, vector<int> &temp, vector<int> &nums, int i){
        if(i == nums.size()){
            ans.insert(temp);
            return;
        }
        makeSubsets(ans, temp, nums, i + 1);
        temp.push_back(nums[i]);
        makeSubsets(ans, temp, nums, i + 1);
        temp.pop_back();
    }
public:
    vector<vector<int>> AllSubsets(vector<int> &arr, int n) {
        set<vector<int>> ans ;
        vector<int> temp;
        sort(arr.begin() , arr.end());
        makeSubsets(ans, temp, arr, 0);
        vector<vector<int>> res;
        for(auto it : ans){
            res.push_back(it);
        }
        return res;
    }
};



// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends