// class Solution {
// public:
//     int numberOfBeams(vector<string>& bank) {
//         int res = 0, count = 0;
//         for (auto &b : bank) {
//             int cnt = count(begin(b), end(b), '1');
//             if (cnt) {
//                 res += count*cnt;
//                 count = cnt;
//             }
//         }
//         return res;
//     }
// };


class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, res = 0;
        for (auto &r : bank) {
            int curr = count(begin(r), end(r), '1');
            if (curr) {
                res += prev * curr;
                prev = curr;
            }
        }
        return res;
    }
};
