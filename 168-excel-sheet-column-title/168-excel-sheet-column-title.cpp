class Solution {
public:
    string convertToTitle(int colNo) {
        string res = "";
        while (colNo--) {
            char tmp = 'A' + colNo % 26;
            res = tmp + res;
            colNo /= 26;
        }
        return res;
    }
};
