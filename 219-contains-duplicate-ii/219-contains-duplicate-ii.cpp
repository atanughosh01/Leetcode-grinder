class Solution_1 {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            // Average case of find() method is O(1) for
            // unordered_map but worst case may be O(n)
            if (mp.find(nums[i]) != mp.end() && abs(mp[nums[i]] - i) <= k) {
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};



class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            // Here even in worst case time would be O(1)
            if (mp[nums[i]] != 0 && abs(mp[nums[i]] - i - 1) <= k) {
                return true;
            }
            mp[nums[i]] = i + 1;
        }
        return false;
    }
};
