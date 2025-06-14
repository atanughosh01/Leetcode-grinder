/*
    class Solution {
    public:
        bool hasAllCodes(string s, int k) {
            int n = s.size(); 
            for(int num = 0; num <= (1 << k); num++){
                string binaryCode = bitset<20>(num).to_string().substr(20-k, k);
                if (s.find(binaryCode) == string::npos) return false;
            }        
            return true;
        }
    };
*/


class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size(); 
        unordered_set<string> set;
        for (int i = 0; i <= n - k; i++)
            set.insert(s.substr(i, k));
        return set.size() == (1 << k);
    }
};
