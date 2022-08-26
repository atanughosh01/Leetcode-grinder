class Solution {
private:
    string sorted_num(int x) {
        string res = to_string(x);
        sort(res.begin(), res.end());
        return res;
    }
public:
    bool reorderedPowerOf2(int n) {
        string n_str = sorted_num(n);
        for (int i = 0; i < 30; i++) {
            if (n_str == sorted_num(1 << i)) {
                return true;
            }
        }
        return false;
    }
};
