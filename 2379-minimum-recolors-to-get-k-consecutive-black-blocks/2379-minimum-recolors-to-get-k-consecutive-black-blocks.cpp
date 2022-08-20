class Solution {
public:
    int minimumRecolors(string &blocks, int k) {
        int mx = 0, count = 0;
        for (int i=0; i <= (blocks.size() - k); i++) {
            count = 0;
            for (int j = i; j < (k + i); j++) {
                if (blocks[j]=='B'){
                    count++;
                }
            }
            mx = max(mx, count);
        }
        return (k - mx);
    }
};
