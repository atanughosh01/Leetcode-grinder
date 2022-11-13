/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
private:
	int func(vector<int> &nums) {
		int len = nums.size(), ans = 0;
		map<int, int> mp;
		for (int i = 0; i < len; i++) {
			mp[nums[i]] = i;
		}
		sort(nums.begin(), nums.end());
		vector<bool> vis(len, false);
		for (int i = 0; i < len; i++) {
			if (vis[i] || mp[nums[i]] == i) {
				continue;
			}
			int j = i, cycle = 0;
			while (!vis[j]) {
				vis[j] = true;
				j = mp[nums[j]];
				cycle++;
			}
			if (cycle > 0) ans += (cycle - 1);
		}
		return ans;
	}
public:
	int minimumOperations(TreeNode *root) {
		queue<TreeNode*> q;
		q.push(root);
		int res = 0;
		while (!q.empty()) {
			int sz = q.size(), i = 0;
			vector<int> arr(sz);
			while (sz--) {
				TreeNode *n = q.front();
				q.pop();
				arr[i++] = n->val;
				if (n->left) q.push(n->left);
				if (n->right) q.push(n->right);
			}
			res += func(arr);
		}
		return res;
	}
};
