#include <vector>
#include <string>
#include <algorithm>
#include <climits>

class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        // Helper function to convert time "HH:MM" to minutes
        auto toMinutes = [](const std::string& time) -> int {
            int hours = std::stoi(time.substr(0, 2));
            int minutes = std::stoi(time.substr(3, 2));
            return hours * 60 + minutes;
        };
        
        // Convert all time points to minutes
        std::vector<int> minutes;
        for (const auto& time : timePoints) {
            minutes.push_back(toMinutes(time));
        }
        
        // Sort the minutes
        std::sort(minutes.begin(), minutes.end());
        
        // Initialize the minimum difference to the maximum possible value (24 hours in minutes)
        int minDiff = INT_MAX;
        
        // Calculate differences between consecutive times
        for (size_t i = 1; i < minutes.size(); ++i) {
            minDiff = std::min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Check the circular difference between the first and last time
        minDiff = std::min(minDiff, 1440 - (minutes.back() - minutes.front()));
        
        return minDiff;
    }
};
