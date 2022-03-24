class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
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
