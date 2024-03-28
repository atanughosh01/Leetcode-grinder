class Solution {
public:
	vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
		int n = nums1.size(), m = nums2.size();
		vector<int> res(n, -1);
		unordered_map<int, int> umap;
		stack<int> st;
		for (int i = 0; i < m; i++) {
			int element = nums2[i];
			while (!st.empty() && element > st.top()) {
				umap[st.top()] = element;
				st.pop();
			}
			st.push(element);
		}
		for (int i = 0; i < n; i++) {
			int elem = nums1[i];
			if (umap.find(elem) != umap.end()) {
				int nge = umap[elem];
				res[i] = nge;
			}
		}
		return res;
	}
};
