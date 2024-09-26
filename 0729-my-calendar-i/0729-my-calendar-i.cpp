class MyCalendar {
private:
    vector<pair<int, int>> bookings; // stores the booked events as pairs of (start, end)

public:
    MyCalendar() {
        // Constructor initializes the bookings list
    }
    
    bool book(int start, int end) {
        // Check for overlap with all previously booked events
        for (auto& [s, e] : bookings) {
            if (max(s, start) < min(e, end)) {
                // Overlap found, return false
                return false;
            }
        }
        // No overlap found, so we can add this booking
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
