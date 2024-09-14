class Solution {
public:
    int dayOfYear(string date) {
        // Extract year, month, and day from the string
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        
        // Days in each month for a non-leap year
        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        // Check if it's a leap year and adjust February's days
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            daysInMonth[1] = 29;
        }
        
        // Calculate the day of the year
        int dayOfYear = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayOfYear += daysInMonth[i];
        }
        dayOfYear += day;
        
        return dayOfYear;
    }
};
