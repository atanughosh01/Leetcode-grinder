/*

// O(N^4) bruteforce TLE solution

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int cnt = 0;
        for(int i : nums1)
            for(int j : nums2)
                for(int k : nums3)
                    for(int l : nums4)
                        if(i + j + k + l == 0)
                            cnt++;
        return cnt;
    }
};


// O(N^3) better but TLE solution

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        for(int l : nums4)
            mp[l]++;
        int cnt = 0;
        for(int i : nums1)
            for(int j : nums2)
                for(int k : nums3)
                        cnt += mp[-(i+j+k)];
        return cnt;
    }
};

*/


// O(N^2) optimal accepted solution

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> mp;
        for(int k : nums3)
            for(int l : nums4)
                mp[k + l]++;
        int cnt = 0;
        for(int i : nums1)
            for(int j : nums2)
                        cnt += mp[-(i + j)];
        return cnt;
    }
};
