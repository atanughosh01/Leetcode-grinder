Let us consider these two arrays [1,4,2,0,6,5,3,7] [1,4,3,7,0,2,6,5]
Now the main observation of the question is-
1. Let's say if i am currently at 5th index in first array then we will find it's corresponding position in second array. In the above example it would be at second last position in second array.
​
​
2. Now for current index my answer would be (common elements in left part of first array and common elements in left part of second array) multiplied by (common elements in right part of first array and common elements in right part of second array).
In above case for 5th index [1,4,2,0] is common in left part and [5] is common in right part.
​
​
3. So, by traversing in this manner we can get our answer but this approach is (O(n^2)) which would not pass the constraints.
So now segment tree comes as our saviour here.
while traversing the array we can update the corresponding positions in segment tree of second array (Initially all nodes in segment tree has 0 value).
By this we can get common elements in left part in O(log n) time using range sum query on segment tree.
And now we have number of common elements in left part, we can easily get common elements in right part using simple maths.
​