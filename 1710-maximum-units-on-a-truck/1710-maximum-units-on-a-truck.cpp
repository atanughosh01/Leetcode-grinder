class Solution {
private:
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[1] > b[1];
    }
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
        int n = (int)(boxTypes.size()), ans  = 0;
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        for (int i = 0; i < n && truckSize > 0; i++) {
            int countOfBoxes = min(boxTypes[i][0], truckSize);
            ans += boxTypes[i][1] * countOfBoxes;
            truckSize -= countOfBoxes;
        }
        return ans;
    }
};
