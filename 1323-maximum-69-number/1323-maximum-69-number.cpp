class Solution_1 {
public:
    int maximum69Number (int num) {
        string numString = to_string(num);
        for (char &currChar : numString) {
            if (currChar == '6') {
                currChar = '9';
                break;
            }
        }
        return stoi(numString);
    }
};



class Solution {
public:
    int maximum69Number (int num) {
        int numCopy = num;
        int indexFirstSix = -1;
        int currDigit = 0;
        while (numCopy > 0) {
            if (numCopy % 10 == 6) {
                indexFirstSix = currDigit;
            }
            numCopy /= 10;
            currDigit++;
        }
        int newNum = 3 * (int)pow(10, indexFirstSix);
        return (indexFirstSix == -1 ? num : num + newNum);
    }
};
