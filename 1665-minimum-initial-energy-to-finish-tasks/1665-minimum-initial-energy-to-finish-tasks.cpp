class Solution {
public:
    int minimumEffort(vector<vector<int>> &tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int> &a, const vector<int> &b){
            return (a[1] - a[0] > b[1] - b[0]); // sort in non-increasing ordere of energy to be borrowed
        });
        int res = 0, energy = 0, borrow = 0;
        for (vector<int> &task : tasks) {
            if (energy < task[1]) {             // if curr energy is less than minimum reqd energy
                borrow = task[1] - energy;      // borrow some energy
                res += borrow;                  // add borrowed energy to ans
                energy += borrow;               // add borrowed energy to current energy
            }
            energy -= task[0];                  // subtract the actual energy reqd to do current task
        }
        return res;
    }
};
