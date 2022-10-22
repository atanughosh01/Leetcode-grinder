1. Initialize an array called `rem`, which contains the needed matching numbers of each character in `s`.
​
2. If there are still characters needed to be contained (increment `i` in this case), decrease the matching number of that character and check if it is still non-negative. If it is, then it is the character in `t`, so decrease the total required number `req`.
​
3. If there are no more characters required (increment `start` in this case), record `min`
and `left` if a smaller length is found. Recover the number of this character in the remaining and if it is a character in `t` increase `req`.
​