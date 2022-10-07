// O(n) time | O(n) space | n = number of unique booking calls made on book()
class MyCalendarOne {
private:
    vector<pair<int, int>> bookings;
public:
    MyCalendarOne() {}
    bool book(int start, int end) {
        for (auto &[s, e] : bookings) {
            if (max(s, start) < min(e, end)) {
                return false;
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};

// O(n*n) time | O(n*n) space | n = number of unique booking calls made on book()
class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings;
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        MyCalendarOne *cal = new MyCalendarOne();
        for (auto &[s, e] : bookings) {
            int _start = max(s, start), _end = min(e, end);
            if (_start < _end && !cal->book(_start, _end)) {
                return false;
            }
        }
        bookings.push_back({start, end});
        return true;
    }
};



/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
