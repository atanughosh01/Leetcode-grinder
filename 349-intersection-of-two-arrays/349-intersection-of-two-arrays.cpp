class Solution {
public:
    /*
    // Time Complexity = O(N*M), Space Complexity = O(N)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;        
        for(int itr = 0; itr < nums1.size(); itr++){
            for(int jtr = 0; jtr < nums2.size(); jtr++){
                if(nums1[itr] == nums2[jtr]){
                    st.insert(nums1[itr]);
                    break;
                }
            }
        }

        vector<int> vt;
        for(auto itr = st.begin(); itr != st.end(); itr++){
            vt.push_back(*itr);
        }
        return vt;
    }
    */
    
    // Time Complexity = O(N), Space Complexity = O(N)
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end());
        vector<int> res;
        for(int itr = 0; itr < nums2.size(); itr++){
            if(st.find(nums2[itr]) != st.end()){
                res.emplace_back(nums2[itr]);
                st.erase(nums2[itr]);
            }            
        }
    return res;
    }
};
