class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int keep = 0, prev = INT_MAX;
        for (int f : freq) {
            if (!f || !prev) break;
            prev = min(f, prev - 1);
            keep += prev;
        }
        return s.size() - keep;
    }
};



class Solution_1 {
public:
    int minDeletions(string &s) {
        vector<int> freq (26, 0);        
        for (char c : s) freq[c - 'a']++;
        sort(freq.begin(), freq.end());
        int del = 0;
        for (int i = 24; i >= 0; i--) {
            if (freq[i] == 0) break;            
            if (freq[i] >= freq[i+1]){
                int prev = freq[i];
                freq[i] = max(0, freq[i+1] -1);
                del += (prev - freq[i]); 
            }
        }
        return del;
    }
};
