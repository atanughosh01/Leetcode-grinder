/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */


class NestedIterator {
private:
    stack<int> stk;
    void dfs(vector<NestedInteger> &nestedList) {
        for(int i=nestedList.size()-1; i>=0; i--) {
            if(nestedList[i].isInteger()) {
                stk.push(nestedList[i].getInteger());
            } else {
                dfs(nestedList[i].getList());
            }
         }
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    int next() {
        int nxt = stk.top();
        stk.pop();
        return nxt;
    }
    bool hasNext() {
        return !stk.empty();
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
