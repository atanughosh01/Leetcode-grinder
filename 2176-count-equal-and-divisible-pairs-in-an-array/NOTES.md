Can we do better than brute-force? We will need it to solve a follow up problem.
​
1. For each number, collect indexes in the increasing order.
2. For a number, go through its indexes:
* Track count of each gcd(j, k) we encountered so far in a map.
* For each index i, check its gcd(i, k) agains GCDs for previous indices.
* Add count to the result if gcd(i, k) * gcd(j, k) % k == 0.
​
​