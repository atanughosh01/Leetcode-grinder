class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int n = tokens.size(), score = 0;
        sort(tokens.begin(), tokens.end());
        int l = 0, r = n - 1;
        while (l < r) {
            if (power >= tokens[l]) {
                power -= tokens[l++];
                score++;
            } else if (score >= 1 && power + tokens[r] >= tokens[l]) {
                power += tokens[r--];
                score--;
            } else {
                break;
            }
        }
        while (l < r + 1 && power >= tokens[l]) {
            power -= tokens[l++];
            score++;
        }
        return score;
    }
};
