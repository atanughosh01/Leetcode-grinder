/*
    class Solution {
    private:
        static bool cmp(const vector<int> &a, const vector<int> &b) {
            return a[1] > b[1];
        }
    public:
        int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
            int ans = 0;
            sort(boxTypes.begin(), boxTypes.end(), cmp);
            for (int i = 0; i < boxTypes.size() && truckSize > 0; i++) {
                int countOfBoxes = min(boxTypes[i][0], truckSize);
                ans += boxTypes[i][1] * countOfBoxes;
                truckSize -= countOfBoxes;
            }
            return ans;
        }
    };
*/


class Solution {
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        int ans = 0, freqBoxes[1001]{0};
        int maxUnit = INT_MIN, minUnit = INT_MAX;
        for (vector<int> &boxType : boxTypes) {
            maxUnit = max(maxUnit, boxType[1]);
            minUnit = min(minUnit, boxType[1]);
            freqBoxes[boxType[1]] += boxType[0];
        }
        for (int i = maxUnit; i >= minUnit && truckSize > 0; i--) {
            if (freqBoxes[i] == 0) continue;
            int countOfBoxes = min(freqBoxes[i], truckSize);
            ans += i * countOfBoxes;
            truckSize -= countOfBoxes;
        }
        return ans;
    }
};
