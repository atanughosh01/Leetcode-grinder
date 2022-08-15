// BrowserHistory_Solution_Using_Doubly_LinkedList
class BrowserHistory_LL {
private:
    // STL Doubly LinkedList in c++
    list<string> history;
    list<string> :: iterator it;

public:
    BrowserHistory_LL(string homepage) {
        history.push_back(homepage);
        it = history.begin();
    }
    
    void visit(string url) {
        auto del = it;
        ++del;
        history.erase(del, history.end());
        history.push_back(url);
        it++;
    }
    
    string back(int steps) {
        while (it != history.begin() && steps--) {
            --it;
        }
        return *it;
    }
    
    string forward(int steps) {
        auto endItr = history.end();
        --endItr;
        while (it != endItr && steps--) {
            ++it;
        }
        return *it;
    }
};




// Solution Using Two Stacks
class BrowserHistory {
private:
    stack<string> history;
    stack<string> future;
    
public:
    BrowserHistory(string homepage) {
        history.push(homepage);
        future = stack<string>();       // Reset the forward stack
    }
    
    void visit(string url) {
        history.push(url);
        future = stack<string>();       // Reset the forward stack
    }
    
    string back(int steps) {
        while (steps-- && history.size() > 1) {  // Always keep at least one element in the stack
            future.push(history.top());
            history.pop();
        }
        return history.top();
    }
    
    string forward(int steps) {
        while(steps-- && future.size() > 0) {
            history.push(future.top());
            future.pop();
        }
        return history.top();
    }
};




/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
