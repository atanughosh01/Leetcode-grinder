class Solution {
public:
    double average(vector<int> &salary) {
        int mx = *max_element(salary.begin(), salary.end());
        int mn = *min_element(salary.begin(), salary.end());
        int sum = accumulate(salary.begin(), salary.end(), 0);
        return (double)(sum - mx - mn) / (salary.size() - 2);
    }
};
