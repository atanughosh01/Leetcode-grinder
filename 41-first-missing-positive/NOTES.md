## Two-Pass Solution
* In first pass (loop), Put each number in its right place `(nums[i] = i + 1)`.
* For example:
When we find 5, swap it with nums[4].
* In second pass (loop), the first `index` where its number is not right, return the `index + 1`.
* Time Complexity: **O(2n) = O(n)**
* Space Complexity: **O(1)**