class Solution {
public:
    string pushDominoes(string &d) {
        d = 'L' + d + 'R';
        int n = d.size(), l = 0, r = 1;
        string res = "";
        while (r < n) {
            if (d[r] == '.') {
                r++;
                continue;
            }
            int mid = r - (l + 1);
            if (l > 0) res += d[l];
            if (d[l] == 'R' && d[r] == 'L') res += string(mid/2, 'R') + string(mid%2, '.') + string(mid/2, 'L');
            else if (d[l] == 'L' && d[r] == 'R') res += string(mid, '.');
            if (d[l] == d[r]) res += string(mid, d[l]);
            l = r++;
        }
        return res;
    }
};


/*
    In this approach, you just need to find sections like this
	X  .   .   .   .  X
	i                 j
	Where X can be 'R' or 'L' and in between there can be as many dots
	Now,
	- you know the length of mid part
	- If char[i] == char[j] == 'R', means all go towards right (R)
	- IF char[i]  == char[j] == 'L', means all go towards Left (L)
	- If char[i] = 'L' and char[j] = 'R', means middle part is not affected so they remain '.'
	- If char[i] = 'R' and char[j] = 'L', then it will affect the middle part.
	   The middle_part/2 close to i will be affected by 'R' and middle_part/2 close to j will be   
	   effected by 'L'  and the last mid point (middle_part%2) will be unaffected due to equal  
	   force from left and right so it remains '.'
*/
