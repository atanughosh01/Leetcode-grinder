class Solution {
public:
	int countTime(string time) {
		int prod = 1;
		if (time[3] == '?') prod *= 6;
		if (time[4] == '?') prod *= 10;
		if (time[0] == '2' && time[1] == '?') prod *= 4;
		else if (time[1] >= '0' && time[1] <= '3' && time[0] == '?') prod *= 3;
		else if (time[1] >= '4' && time[1] <= '9' && time[0] == '?') prod *= 2;
		else if (time[0] != '?' && time[1] == '?') prod *= 10;
		else if (time[0] == '?' && time[1] == '?') prod *= 24;
		return prod;
	}
};
