class Solution {
private:
    static bool compare(pair<int,int>& a, pair<int,int>& b){
       return a.second > b.second;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int& num : nums)
            mp[num]++;
        vector<pair<int,int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), compare);
        nums.clear();
        for(int i=0; i<k; i++)
            nums.emplace_back(v[i].first);
        return nums;
    }
};
