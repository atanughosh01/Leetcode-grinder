/*
    class Solution {
    public:
        int maxOperations(vector<int> &nums, int k) {
            int cnt = 0;
            unordered_map<int, int> mp;
            for (int num : nums) mp[num]++;
            for (int num : nums) {
                auto itr = mp.find(k - num);
                if (itr != mp.end() && mp[k - num] > 0) {
                    mp[k - num]--;
                    if (mp[num] > 0) {
                        mp[num]--;
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    };
*/


class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
      int cnt = 0;
      unordered_map<int, int> mp;
      for (int num : nums) mp[num]++;           // count freq of nums
      for (auto itr=mp.begin(); itr!=mp.end(); itr++) {
        int num = itr->first, freq = itr->second;
        if (k - num == num) cnt += freq/2;      // if num is half of k add half of it's count in ans
        else if (mp.count(k - num)) {           // find k-num in nums and add min freq of num or k-num to ans
          int mn = min(freq, mp[k-num]);
          cnt += mn;
          mp[num] -= mn;
          mp[k-num] -= mn;
        }
      }
      return cnt;
    }
};
