/*
    class WordFilter {
    private:
        unordered_map<string, int> hashMap;

    public:
        WordFilter(vector<string> &words) {
            int n = words.size();
            for (int i = 0; i < n; i++) {
                string word = words[i];
                int wordSize = word.size();
                for (int j = 1; j <= wordSize; j++) {
                    string p = word.substr(0, j);
                    for (int k = 0; k < wordSize; k++) {
                        string s = word.substr(k, wordSize);
                        hashMap[p + "|" + s] = i + 1;
                    }
                }
            }
        }

        int f(string prefix, string suffix) {
            string s = prefix + "|" + suffix;
            return hashMap[s] - 1;
        }
    };
*/



class Trie {
private:
    Trie* ch[27];
    int weight;

public:
    Trie() {
        memset(ch, 0, sizeof(ch));
        weight = 0;
    }

    void insert(string str, int weight) {
        Trie* node = this;
        for (char c : str) {
            if (node->ch[c - 'a'] == NULL)
                node->ch[c - 'a'] = new Trie();
            node = node->ch[c - 'a'];
            node->weight = weight;
        }
    }

    int startsWith(string str) {
        Trie* node = this;
        for (char c : str) {
            if (node->ch[c - 'a'] == NULL)
                return -1;
            node = node->ch[c - 'a'];
        }
        return node->weight;
    }
};

class WordFilter {
public:
    Trie root;
    WordFilter(vector<string> &words) {
        int idx = 0;
        for (string word : words) {
            root.insert(word, idx);
            string tmp = "{" + word;
            for (int i = word.length() - 1; i >= 0; i--) {
                string newWord = word[i] + tmp;
                tmp = newWord;
                root.insert(newWord, idx);
            }
            idx++;
        }
    }

    int f(string prefix, string suffix) {
        string word = suffix + "{" + prefix;
        return root.startsWith(word);
    }
};



/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
