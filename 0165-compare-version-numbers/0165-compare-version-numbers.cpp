class Solution_1 {
private:
    vector<int> listOfRevisions(string &str) {
        str += '.';
        vector<int> res;
        int cnt = 0, l = 0;
        for (int i = 0; i < str.size(); i++) {
            cnt++;
            if (str[i] == '.') {
                string s = str.substr(l, cnt);
                res.push_back(stoi(s));
                cnt = 0;
                l = i + 1;
            }
        }
        return res;
    }
public:
    int compareVersion(string &ver1, string &ver2) {
        vector<int> ver1Nums = listOfRevisions(ver1);
        vector<int> ver2Nums = listOfRevisions(ver2);
        int n = max(ver1Nums.size(), ver2Nums.size());
        ver1Nums.resize(n, 0);
        ver2Nums.resize(n, 0);
        for (int i = 0; i < n; i++) {
            if (ver1Nums[i] < ver2Nums[i]) {
                return -1;
            } else if (ver1Nums[i] > ver2Nums[i]) {
                return 1;
            }
        }
        return 0;
    }
};



class Solution {
public:
    int compareVersion(string &version1, string &version2) {
        int i = 0, j = 0, num1 = 0, num2 = 0;
        int n1 = version1.size(), n2 = version2.size();
        while (i<n1 || j<n2) {
            while (i<n1 && version1[i]!='.'){
                num1 = num1*10+(version1[i]-'0');
                i++;
            }
            while (j<n2 && version2[j]!='.') {
                num2 = num2*10+(version2[j]-'0');
                j++;
            }
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;
            num1 = 0; num2 = 0;
            i++; j++;
        }
        return 0;
    }
};
