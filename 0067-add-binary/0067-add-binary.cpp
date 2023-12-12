#define ull unsigned long long

class Solution_1 {
private:
    ull convToBinary(int N) {
        ull ans = 0;
        int cnt = 0;
        while (N != 0) {
            int rem = N % 2;
            ull c = pow(10, cnt);
            ans += rem * c;
            N /= 2;
            cnt++;
        }
        return ans;
    }
public:
    string addBinary(string a, string b) {
        ull n1 = (ull)stoi(a, 0, 2);
        ull n2 = (ull)stoi(b, 0, 2);
        ull bin_sum = convToBinary(n1+n2);
        return to_string(bin_sum);
    }
};


class Solution {
public:
    string addBinary(string &a, string &b) {
        auto output = ""s;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0 && a[i--] == '1') ++carry;
            if (j >= 0 && b[j--] == '1') ++carry;
            output.insert(0, carry % 2 == 1 ? "1" : "0");
            carry /= 2;
        }
        return output;
    }
};
