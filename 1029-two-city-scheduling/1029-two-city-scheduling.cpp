/*
    class Solution {
    public:
        int twoCitySchedCost(vector<vector<int>>& costs) {
            int minCost = 0, n = costs.size()/2;
            vector<int> refund;
            for(vector<int> cost : costs){
                minCost += cost[0];
                refund.emplace_back(cost[1]-cost[0]);
            }
            sort(refund.begin(), refund.end());
            for(int i=0; i<n; i++) {
                minCost += refund[i];
            }
            return minCost;
        }
    };
*/


class Solution {
private:
    // dp[i][j] represents minimum cost of flying i+j people, such that i people should go to city A and j people should go to city B 
    int dp[51][51]; 
    int minCost(int i, int a, int b, int n, vector<vector<int>>& costs){
        if(i == n) return 0;
        if(dp[a][b] != -1) return dp[a][b];
        int mini = INT_MAX;
        //for i th person, we have 2 options
        //i th person may go to city A
        if(a>0) mini = min(mini, costs[i][0] + minCost(i+1,a-1,b,n,costs));
        //i th person may go to city B
        if(b>0) mini = min(mini, costs[i][1] + minCost(i+1,a,b-1,n,costs));
        return dp[a][b] = mini;
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        memset(dp, -1, sizeof(dp));
        return minCost(0, n, n, 2*n, costs);    
    }
};
