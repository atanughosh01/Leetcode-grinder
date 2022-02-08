The `O(n*logn)` solution is actually harder to implement that the `O(n)` solution, although the former one is less-efficient.
​
* Solution using **Prefix Sum** ->   Time Complexity = **O(n*logn)**
* Solution using **Two Pointers**  ->  Time Complexity = **O(n)**

**QnA**
1. *Both the for/while loop and (another) while loop has O(n) time complexity individually . However, the while loop is in the internal of the for loop. Shouldn't the two be multiplied?
Why add ?*
* its simple, both of the two loop are not running for each and every indices. 1st loop only runs for every index, 2nd while loop will only run for given condition so time complexity will be O(N+N) times in a worst case also. O(N+N) is equal to O(N)
