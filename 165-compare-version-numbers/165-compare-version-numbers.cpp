class Solution {
private:
	vector<int> listOfRevisions(string str) {
		str += '.';
		vector<int> res;
		int cnt = 0, l = 0;
		for (int i = 0; i < str.size(); i++) {
			cnt++;
			if (str[i] == '.') {
				string s = str.substr(l, cnt);
				res.push_back(stoi(s));
				cnt = 0;
				l = i + 1;
			}
		}
		return res;
	}
public:
	int compareVersion(string ver1, string ver2) {
		vector<int> ver1Nums = listOfRevisions(ver1);
		vector<int> ver2Nums = listOfRevisions(ver2);

		int n = max(ver1Nums.size(), ver2Nums.size());
		ver1Nums.resize(n, 0);
		ver2Nums.resize(n, 0);

		for (int i = 0; i < n; i++) {
			if (ver1Nums[i] < ver2Nums[i])
				return -1;
			else if (ver1Nums[i] > ver2Nums[i])
				return 1;
		}
		return 0;
	}
};
