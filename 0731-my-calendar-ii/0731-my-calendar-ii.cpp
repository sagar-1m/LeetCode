class MyCalendarTwo {
public:
    // Store intervals that are single and double booked
    vector<pair<int, int>> bookings;
    vector<pair<int, int>> doubleBookings;

    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        // Check if this event would cause a triple booking
        for (auto& [dStart, dEnd] : doubleBookings) {
            if (max(start, dStart) < min(end, dEnd)) {
                // There is an overlap with a double booking, so return false
                return false;
            }
        }
        
        // Now add the new booking and update doubleBookings if needed
        for (auto& [bStart, bEnd] : bookings) {
            // Calculate overlap between the new booking and existing ones
            int overlapStart = max(start, bStart);
            int overlapEnd = min(end, bEnd);
            
            if (overlapStart < overlapEnd) {
                // If there is an overlap, it should be added to doubleBookings
                doubleBookings.push_back({overlapStart, overlapEnd});
            }
        }
        
        // Finally, add this event to the bookings list
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
