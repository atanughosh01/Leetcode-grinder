class Solution {
private:
    vector<string> ans, mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(string &digits, int i, string comb){	
        if (i == digits.size()) {
            ans.push_back(move(comb));    
        } else {
            for (char c : mappings[digits[i] - '2']) {
                helper(digits, i + 1, comb + c);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return ans;
        helper(digits, 0, "");              
        return ans;
    }
};
