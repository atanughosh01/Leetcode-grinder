class SolutionWrong {
private:
    bool isSubset(string &a, string &b) {
        string x = a, y = b;
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        for (char &c : y) {
            if (!binary_search(x.begin(), x.end(), c)) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        vector<string> res;
        for (int i = 0; i < words1.size(); i++) {
            for (int j = 0; j < words2.size(); j++) {
                if (!isSubset(words1[i], words2[j])) {
                   break; 
                }
                if (j == words2.size() - 1 && isSubset(words1[i], words2[j])) {
                    res.push_back(words1[i]);
                }
            }
        }
        return res;
    }
};



// TC : O(w1.len + w2.len), SC : O(w1.len)->result array
class Solution {
private:
    bool isSubset(int *big, int *small) {
        for (int i = 0; i < 26; i++) {
            if (small[i] > big[i]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        vector<string> res;
        int *freq2 = new int[26]{0};
        for (string &str2 : words2) {
            int *temp = new int[26]{0};
            for (char &c : str2) {
                temp[c-'a']++;
                freq2[c-'a'] = max(freq2[c-'a'], temp[c-'a']);
            }
            delete [] temp;
        }
        for (string &str1 : words1) {
            int *freq1 = new int[26]{0};
            for (char &c : str1) {
                freq1[c-'a']++;
            }
            if (isSubset(freq1, freq2)) {
                res.push_back(str1);
            }
            delete [] freq1;
        }
        
        delete [] freq2;
        return res;
    }
};
