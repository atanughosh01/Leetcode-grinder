class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        vector<long long> result;
        long long start = intLength % 2 ? pow(10, intLength/2) : pow(10, intLength/2 - 1);
        
        for(int q : queries) { 
            string s = to_string(start + q - 1);
            string palindrome = s;
            reverse(s.begin(), s.end());
            
            if(intLength % 2 == 0) palindrome += s;
            else palindrome += s.substr(1, s.size() - 1);
            
            if (palindrome.size() == intLength)
                result.emplace_back(stoll(palindrome));
            else
                result.emplace_back(-1);
        }
        return result;
    }
};
