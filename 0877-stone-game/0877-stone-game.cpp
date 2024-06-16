class Solution {
private:
	int sum1 = 0, sum2 = 0;
	void func(vector<int> &piles, int st, int ed, bool flag) {
		if (st > ed) return;
		if (flag) {
			if (piles[st] > piles[ed]) {
				sum1 += piles[st];
				func(piles, st + 1, ed, !flag);
			} else {
				sum1 += piles[ed];
				func(piles, st, ed - 1, !flag);
			}
		} else {
			if (piles[st] > piles[ed]) {
				sum2 += piles[st];
				func(piles, st + 1, ed, !flag);
			} else {
				sum2 += piles[ed];
				func(piles, st, ed - 1, !flag);
			}
		}
	}
public:
	bool stoneGame(vector<int> &piles) {
		func(piles, 0, piles.size() - 1, true);
		if (sum1 > sum2) {
			return true;
		}
		return true;
	}
};
