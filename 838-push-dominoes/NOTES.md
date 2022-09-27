In this approach, you just need to find sections like this\
l-> X  .   .   .   .  X <-r\
Where X can be 'R' or 'L' and in between there can be as many dots\
Now,
- you know the length of mid part
- If `char[l] == char[r] == 'R'`, means all go towards right (R)
- IF `char[l] == char[r] == 'L'`, means all go towards Left (L)
- If `char[l] = 'L' and char[r] = 'R'`, means middle part is not affected so they remain '.'
- If `char[l] = 'R' and char[r] = 'L'`, then it will affect the middle part.
The middle_part/2 close to i will be affected by 'R' and middle_part/2 close to j will be
effected by 'L'  and the last mid point (middle_part%2) will be unaffected due to equal
force from left and right so it remains '.'
