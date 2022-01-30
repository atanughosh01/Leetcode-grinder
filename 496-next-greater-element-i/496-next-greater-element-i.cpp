class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        unordered_map<int, int> umap;
        stack<int> st;
        for(int i=0; i<nums2.size(); i++) {
            int element = nums2[i];
            while(!st.empty() && element > st.top()) {
                umap[st.top()] = element;
                st.pop();
            }
            st.push(element);
        }
        for(int i=0; i<nums1.size(); i++) {
            int elem = nums1[i];
            if(umap.find(elem) != umap.end()) {
                int nge = umap[elem];
                res[i] = nge;
            }
        }
        return res;
    }
};
