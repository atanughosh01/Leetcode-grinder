class Solution_1 {
public:
    int minimumRecolors(string &blocks, int k) {
        int mx = 0, count = 0;
        for (int i = 0; i <= (blocks.size() - k); i++) {
            count = 0;
            for (int j = i; j < (k + i); j++) {
                if (blocks[j] == 'B'){
                    count++;
                }
            }
            mx = max(mx, count);
        }
        return (k - mx);
    }
};



class Solution {
public:
    int minimumRecolors(string &blocks, int k) {
        int back = 0, front = 0, count = 0, ans = INT_MAX;
        while (front < blocks.size()){
            if (blocks[front] == 'W') count++;
            if (front - back + 1 == k) {
                ans = min(ans, count);
                if (blocks[back] == 'W') count--;
                back++;
            }
            front++;
        }
        return ans;
    }
};
