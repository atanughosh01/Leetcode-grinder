class Solution_1 {
public:
	int numRescueBoats(vector<int> &people, int limit) {
		int maxBoats = 0, r = people.size() - 1, l = 0;
		sort(people.begin(), people.end());
		while (l <= r) {
			if (people[l] + people[r] <= limit) l++;
			r--;
			maxBoats++;
		}
		return maxBoats;
	}
};


class Solution {
public:
	int numRescueBoats(vector<int> &people, int limit) {
		vector<int> bucket(limit + 1, 0);
		int j = limit, i = 0;
		for (int x : people) bucket[x]++;
		int curr = limit, ans = 0;
		while (i <= j) {
			while (i <= j && bucket[i] <= 0) i++;
			while (i <= j && bucket[j] <= 0) j--;
			if (i > j || (bucket[j] == 0 && bucket[i] == 0)) break;
			ans++;
			if (j + i <= limit) bucket[i]--;
			bucket[j]--;
		}
		return ans;
	}
};
