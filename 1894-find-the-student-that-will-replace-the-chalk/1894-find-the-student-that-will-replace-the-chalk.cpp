class Solution {
public:
    int chalkReplacer(vector<int> &chalk, int k) {
        auto sum = accumulate(chalk.begin(), chalk.end(), 0ll);
        k %= sum;
        for (int i = 0; i < chalk.size(); i++) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return 0;
    }
};
