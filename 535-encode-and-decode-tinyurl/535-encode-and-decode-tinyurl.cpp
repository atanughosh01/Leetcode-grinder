/*

// Chad Solution :)
class Solution {
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
       return longUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
       return shortUrl;        
    }
};

*/


// Optimal Solution
class Solution {
private:

    // Database
    unordered_map<string, string> codeDB, urlDB;
    const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int len = (int)chars.size(), idx = 0;

    // Generates a random 6 character alphanumeric string
    string gencode() {
        string code = "";
        for(int i=0; i<6; ++i) {
            idx = rand() % len;
            code += chars[idx];
        }
        return "http://tinyurl.com/" + code;
    }

public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if(urlDB.find(longUrl) != urlDB.end())
            return urlDB[longUrl];
        
        string code = gencode();
        while(codeDB.find(code) != codeDB.end())
            code = gencode();
        
        codeDB[code] = longUrl;
        urlDB[longUrl] = code;
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string str = codeDB[shortUrl];
        return str;
    }
};


// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
