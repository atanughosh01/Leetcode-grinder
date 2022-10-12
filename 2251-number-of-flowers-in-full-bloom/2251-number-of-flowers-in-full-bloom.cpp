class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons) {
        vector<int> start, end, res;
        for (auto &flower : flowers) {
            start.push_back(flower[0]);
            end.push_back(flower[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for (int &person : persons) {
            int started = upper_bound(start.begin(), start.end(), person) - start.begin();
            int ended = lower_bound(end.begin(), end.end(), person) - end.begin();
            res.push_back(started - ended);
        }
        return res;
    }
};
