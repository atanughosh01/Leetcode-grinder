<br><br>
Complexity Analysis
<br>
Time: O(m * n * log n), where m is the number of queries. 140 ms runtime in OJ.
<br>
Memory: O(n) to make a copy of an array.
​
​
<br><br>
Approach 2: Count Patterns
<br>
This is a bit more complicated, but helps avoid sorting the array. For each subarray, we determine the min and max elements. This will allow us to determine the pattern: pat = (max - min) / (len - 1). Then, for the arithmetic sequence, (nums[j] - min_e) / pat will be the position of that number in the sequence. So, we can go through our subarray again, and check that all positions are filled. We can use a boolean array to do so; if we try to fill a position that has been already filled, we can terminate - the subarray does not form the sequence.
​
```
class Solution {
public:
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
vector<bool> res;
for (auto i = 0; i < l.size(); ++i) {
int mn_e = INT_MAX, mx_e = INT_MIN, len = r[i] - l[i] + 1, j = l[i];
for (int j = l[i]; j <= r[i]; ++j) {
mn_e = min(mn_e, n[j]);
mx_e = max(mx_e, n[j]);
}
if (mx_e == mn_e) res.push_back(true);
else if ((mx_e - mn_e) % (len - 1)) res.push_back(false);
else {
vector<bool> diffs(len);
int pat = (mx_e - mn_e) / (len - 1);
for (; j <= r[i]; ++j) {
if ((n[j] - mn_e) % pat || diffs[(n[j] - mn_e) / pat])
break;
diffs[(n[j] - mn_e) / pat] = true;
}
res.push_back(j > r[i]);
}
}
return res;
}
};
```
​
<br><br>
Complexity Analysis
<br>
Time: O(m * n), 28 ms runtime in OJ.
<br>
Memory: O(n / 32) for the boolean array.