class Solution {
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        int i = 0, j = 0, cnt = 0;
        while (i < players.size() and j < trainers.size()) {
            if (players[i] <= trainers[j++]) cnt++, i++;
        }
        return cnt;
    }
};
