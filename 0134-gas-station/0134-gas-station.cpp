class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_tank = 0;   // To track the overall balance of gas - cost
        int curr_tank = 0;    // To track the current gas balance on this route
        int start_station = 0; // Start station index
        
        for (int i = 0; i < gas.size(); ++i) {
            total_tank += gas[i] - cost[i];
            curr_tank += gas[i] - cost[i];
            
            // If curr_tank drops below 0, we can't start from the current station or any before it
            if (curr_tank < 0) {
                start_station = i + 1; // Try starting from the next station
                curr_tank = 0;         // Reset current tank for the new starting point
            }
        }
        
        // If total_tank is negative, it's impossible to complete the circuit
        return total_tank >= 0 ? start_station : -1;
    }
};
