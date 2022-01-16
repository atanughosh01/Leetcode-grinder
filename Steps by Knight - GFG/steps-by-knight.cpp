// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
public:

	bool check(int N, int x, int y) {
	    if(x >= 0 and y >= 0 and x < N and y < N) return true;
	    return false;
	}

	int minStepToReachTarget(vector<int>&k,vector<int>&t,int N)	{
	    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
	    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
	    
	    int **grid = new int*[N];
	    for(int i=0; i<N; i++) {
	        grid[i] = new int[N];
	        for(int j=0; j<N; j++) {
	            grid[i][j] = -1;
	        }
	    }
	    grid[k[0]-1][k[1]-1] = 0;
	    queue<pair<int, int>> q;
	    q.push({k[0]-1, k[1]-1});

	    while(!q.empty()) {
	        int currX = q.front().first;
	        int currY = q.front().second;
	        q.pop();
	        for(int i=0; i<8; i++) {
	            int targetX = currX + dx[i];
	            int targetY = currY + dy[i];
	            if(check(N, targetX, targetY) and grid[targetX][targetY] == -1) {
	                grid[targetX][targetY] = grid[currX][currY] + 1;
	                if(targetX == t[0]-1 and targetY == t[1]-1) {
	                    return grid[targetX][targetY];
	                }
	                q.push({targetX, targetY});
	            }
	        }
	    }
	    int ans = grid[t[0]-1][t[1]-1];
	    for(int i=0; i<N; i++) delete grid[i];
	    delete grid;
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends