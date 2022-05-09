class Solution {
private:
    vector<string> mappings = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, ans;
    void helper(string &digits, int i, string combi){	
        if(i == digits.size()) {
            ans.push_back(move(combi));    
        } else {
            for(auto c : mappings[digits[i] - '2']) {
                helper(digits, i + 1, combi + c);
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return ans;
        helper(digits, 0, "");              
        return ans;
    }
};
