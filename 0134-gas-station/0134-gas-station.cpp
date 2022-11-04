class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int gas_tank = 0, start_idx = 0;
        int n = gas.size(), sum = 0;
        for (int i=0; i<n; i++) {
            sum += gas[i] - cost[i];
            gas_tank += gas[i] - cost[i];
            if (gas_tank < 0) {
                start_idx = i+1;
                gas_tank = 0;
            }
        }
        return (sum < 0) ? -1 : start_idx;
    }
};
