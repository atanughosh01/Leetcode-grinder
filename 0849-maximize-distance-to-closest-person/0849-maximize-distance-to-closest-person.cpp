class Solution_1 {
public:
    int maxDistToClosest(vector<int> &seats) {
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


class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {     
        int pre_zeros = -1, suf_zeros = -1, max_zeros = -1, zeros = 0;
        for (int i = 0; i < seats.size(); i ++) {
            if (seats[i] == 0) zeros ++;
            else {
                if (pre_zeros == -1) pre_zeros = zeros;
                else max_zeros = max(max_zeros, zeros);
                zeros = 0;
            }
        } 
        suf_zeros = zeros;
        return max(max(pre_zeros, suf_zeros), (max_zeros + 1) / 2);
    }
};
