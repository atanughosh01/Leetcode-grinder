class LUPrefix {
private:
    int m = 1;
    vector<int> arr;
public:
    LUPrefix(int n) {
        vector<int> a(n + 2, 0);
        m = 1;
        arr = a;
        arr[0] = 1;
    }
    void upload(int v) {
        arr[v] = 1;
        while (arr[m]) m++;
    }
    int longest() {
        return m - 1;
    }
};



/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
