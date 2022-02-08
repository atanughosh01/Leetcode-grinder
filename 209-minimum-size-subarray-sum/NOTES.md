dThe `O(n*logn)` solution is actually harder to implement that the `O(n)` solution, although the formaer one is less-efficient.
​
* Solution using **Prefix Sum** ->   Time Complexity = **O(n)**
* Solution using **Binary Search**  ->  Time Complexity = **O(n*logn)**
​
**QnA:**
1. *Both the for loop and while loop has O(n) time complexity in total. However, the while loop is in the internal of the for loop. Shouldn't the two be multiplied?
Why add ?*
* its simple, two loop are not running for each and every indices. 1st loop only runs for every index, 2nd while loop will only run for given condition so time complexity will be O( N+N) times in a worst case also.
O(N+N) is equal to O(N)