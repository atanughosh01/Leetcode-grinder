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
