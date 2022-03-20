// class Solution {
// public:
//     int countCollisions(string dir) {
//         int n = dir.length();
//         if (n%2) {
//             dir += 'R';
//             n++;
//         }
//         int res = 0;
//         for (int i=0; i<n-1; i++) {
//             if (dir[i] == 'R' && dir[i+1] == 'S') {
//                 res++;
//                 dir[i] = 'S';
//             }
//             if (dir[i] == 'R' && dir[i+1] == 'L') {
//                 res+=2;
//                 dir[i] = 'S';
//                 dir[i+1] = 'S';
//             }
//             if (dir[i] == 'S' && dir[i+1] == 'L') {
//                 res++;
//                 dir[i+1] = 'S';
//             }
//         }
//         return res;
//     }
// };



class Solution {
public:
    int countCollisions(string D) {                 // D is Direction string
        int n = D.size(), ans = 0;
		int i = 0, j = n-1;
        while(i<=j and D[i] == 'L') i++;            // Cars on left going left => no colision
		while(i<=j and D[j] == 'R') j--;            // Cars on right going right => no colision
        for(; i<=j; i++) ans += (D[i] != 'S');    // Whether S collides or not it doesn't change answer, all other collide and change score
        return ans;
    } 
};
