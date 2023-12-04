class Solution {
private:
    void generate(int left, int right, string s, vector<string> &res) {
        if (left == 0 && right == 0) {
            res.push_back(s);
            return;
        }
        if (left > 0) {
            generate(left - 1, right, s + '(', res);
        }
        if (right > left) {
            generate(left, right - 1, s + ')', res);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        generate(n, n, s, res);
        return res;
    }
};
