class Solution {
   public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string start = max(arriveAlice, arriveBob), end = min(leaveAlice, leaveBob);
        if (start <= end) {
            int startMonth = stoi(start.substr(0, 2)), startDate = stoi(start.substr(3, 2));
            int endMonth = stoi(end.substr(0, 2)), endDate = stoi(end.substr(3, 2));
            if (endMonth == startMonth) return endDate - startDate + 1;
            int days = month[startMonth] + endDate - startDate + 1;
            for (int i = startMonth + 1; i < endMonth; i++) days += month[i];
            return days;
        }
        return 0;
    }
};
