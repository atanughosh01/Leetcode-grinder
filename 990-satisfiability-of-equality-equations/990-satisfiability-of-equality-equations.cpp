class Solution {
private:
    int uf[26];
    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
public:
    bool equationsPossible(vector<string> &equations) {
        for (int i = 0; i < 26; i++) uf[i] = i;
        for (string &eqn : equations) {
            if (eqn[1] == '=') {
                uf[find(eqn[0] - 'a')] = find(eqn[3] - 'a');
            }
        }
        for (string &eqn : equations) {
            if (eqn[1] == '!' && find(eqn[0] - 'a') == find(eqn[3] - 'a')) {
                return false;
            }
        }
        return true;
    }
};
