class Solution {
public:
    double soupServings(int n) {
        if (n >= 4300) return 1.0;
        unordered_map<string, double> memo;
        return serve(n, n, memo);        
    }
private:
    double serve(int A, int B, unordered_map<string, double> &memo) {
        string key = to_string(A) + "-" + to_string(B);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        if (A <= 0 && B <= 0) return 0.5;
        if (A <= 0) return 1.0;
        if (B <= 0) return 0.0;
        double prob = 0.25 * (serve(A - 100, B, memo) + serve(A - 75, B - 25, memo) + serve(A - 50, B - 50, memo) + serve(A - 25, B - 75, memo));
        memo[key] = prob;
        return prob;
    }    
};
