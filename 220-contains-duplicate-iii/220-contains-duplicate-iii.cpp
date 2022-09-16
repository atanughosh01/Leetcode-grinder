typedef long long ll;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff) {
        unordered_map<int, int> buckets;
        for (int i = 0; i < nums.size(); ++i) {
            int buck = nums[i] / ((ll)valueDiff + 1);
            if (nums[i] < 0) buck--;
            if (buckets.find(buck) != buckets.end()) {
                return true;
            } else {
                buckets[buck] = nums[i];
                if (buckets.find(buck - 1) != buckets.end() && (ll)nums[i] - buckets[buck - 1] <= valueDiff) {
                    return true;
                } else if (buckets.find(buck + 1) != buckets.end() && (ll)buckets[buck + 1] - nums[i] <= valueDiff) {
                    return true;
                } else if (buckets.size() > indexDiff) {
                    int key_to_remove = nums[i - indexDiff] / ((ll)valueDiff + 1);
                    if (nums[i - indexDiff] < 0) key_to_remove--;
                    buckets.erase(key_to_remove);
                }
            }
        }
        return false;
    }
};
