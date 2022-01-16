class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int len = seats.size(), i = 0, j, res = 0;
        bool isNotTerminal;
        while (i < len) {
            while (i < len && seats[i]) i++;
            j = i + 1;
            while (j < len && !seats[j]) j++;
            isNotTerminal = i && j != len;
            res = max(res, (j - i + isNotTerminal) / (1 + isNotTerminal));
            i = j;
        }
        return res;
    }
};
