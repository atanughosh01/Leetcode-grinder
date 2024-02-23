class Solution_1 {
public:
    bool wordPattern(string &pattern, string &str) {
        vector<int> pat_map (26, 0);
        unordered_map<string,int> str_map;
        int i=0, n = pattern.size();
        istringstream ss (str);
        string token;
        for(string token; ss >> token; ++i) {
            if(i == n || pat_map[pattern[i]-'a'] != str_map[token]) return false;
            pat_map[pattern[i]-'a'] = str_map[token] = i+1;
        }
        return i == n;
    }
};


class Solution {
public:
    bool wordPattern(string &pattern, string &s) {
        unordered_map<char, string> StoP; 
        unordered_map<string, char> PtoS;
        
        stringstream sss(s); // Used for breaking words
        string word; // To store individual words
        
        // if length of both pattern and s is diff then return false
        int count = 0;
        while (sss >> word)
            count++;
        if(count != pattern.length())
            return false;
        
        int i=0;
        stringstream ss(s); 
        string Word;
        while(ss >> Word) {            
            // if mapping dosen't exist in either of the maps
            if(StoP.find(pattern[i]) == StoP.end() && PtoS.find(Word) == PtoS.end()) {
                StoP[pattern[i]] = Word;
                PtoS[Word] = pattern[i];
            } 
            // if mapping dosen't exist in one of the maps or mapping exist but dosen't match
            else if(!(StoP[pattern[i]] == Word && PtoS[Word] == pattern[i])) {
                return false;
            }
            i++;
        }
        return true;
    }
};
