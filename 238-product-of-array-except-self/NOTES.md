Trial:
​
```
class Solution {
public:
vector<int> productExceptSelf(vector<int>& nums) {
int n = (int)nums.size();
vector<int> ans(n, 0), pf(n);
pf[0] = nums[0];
for(int i=1; i<n; ++i) {
if(nums[i] != 0){
pf[i] = pf[i-1]*nums[i];
} else {
pf[i] = pf[i-1];
}
}
}
};
```