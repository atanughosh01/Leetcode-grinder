// O(N) Solution
class Solution_1 {
private:
    const int val[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string rom[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
public:
    string intToRoman(int num) {
        string roman = "";
        for (int i = 0; num > 0; i++) {
            while (num >= val[i]) {
                roman += rom[i];
                num -= val[i];
            }
        }
        return roman;
    }
};



// O(1) Solution
class Solution {
private:
    const string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    const string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    const string hdrs[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    const string thsd[10] = {"", "M", "MM", "MMM"};
public:
    string intToRoman(int num) {
        return thsd[num/1000] + hdrs[(num%1000)/100] + tens[(num%100)/10] + ones[num%10];
    }
};
