class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleNumber = 0;
        
        // Iterate over each bit position (0 to 31 for 32-bit integers)
        for (int i = 0; i < 32; ++i) {
            int bitSum = 0;
            for (int num : nums) {
                // Count how many numbers have the i-th bit set
                if (num & (1 << i)) {
                    bitSum += 1;
                }
            }
            // If bitSum is not a multiple of 3, the single number has this bit set
            if (bitSum % 3 != 0) {
                singleNumber |= (1 << i);
            }
        }
        
        return singleNumber;
    }
};
