class Solution_1 {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        for (int i = 0, j; i < words.size(); i = j) {
            int width = 0;
            for (j = i; j < words.size() && width + words[j].size() + j - i <= maxWidth; j++) {
                width += words[j].size();
            }
            int space = 1, extra = 0;
            if (j - i != 1 && j != words.size()) {
                space = (maxWidth - width) / (j - i - 1);
                extra = (maxWidth - width) % (j - i - 1);
            }
            string line = words[i];
            for (int k = i + 1; k < j; k++) {
                line += string(space, ' ');
                if (extra-- > 0) line += " ";
                line += words[k];
            }
            line += string(maxWidth - line.size(), ' ');
            res.push_back(line);
        }
        return res;
    }
};





class Solution {
private:
	string leftJustify(vector<string> &arr, int diff, int l, int r) {
		string ans = arr[l];
		int spacesOnRight = diff - (r - l - 1);
		for (int i = l + 1; i < r; i++) {
			ans += (" " + arr[i]);
		}
		ans += string(spacesOnRight, ' ');
		return ans;
	}
	string middleJustify(vector<string> &arr, int diff, int l, int r) {
		string ans = arr[l];
		int spacesNeeded = r - l - 1;
		int spaces = diff / spacesNeeded;
		int extraSpaces = diff % spacesNeeded;
		for (int i = l + 1; i < r; i++) {
			int spacesToApply = spaces + (extraSpaces-- > 0);
			ans += (string(spacesToApply, ' ') + arr[i]);
		}
		return ans;
	}
public:
	vector<string> fullJustify(vector<string> &words, int maxWidth) {
		vector<string> res;
		int i = 0, n = words.size();
		while (i < n) {
			int j = i + 1, lineLength = words[i].size();
			while (j < n && (lineLength + words[j].size() + (j - i - 1) < maxWidth)) {
				lineLength += words[j].size();
				j++;
			}
			int diff = maxWidth - lineLength;
			int wordsCount = j - i;
			if (wordsCount == 1 || j >= n) res.push_back(leftJustify(words, diff, i, j));
			else res.push_back(middleJustify(words, diff, i, j));
			i = j;
		}
		return res;
	}
};
