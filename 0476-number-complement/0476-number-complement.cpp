class Solution {
public:
    int findComplement(int num) {
          if (num == 0) return 1;

    // Initialize a mask to flip all bits of num
    int mask = 0;
    int temp = num;
    
    // Create mask with the same length as the binary representation of num
    while (temp != 0) {
        mask = (mask << 1) | 1; // Shift mask left by 1 and add 1
        temp >>= 1; // Right shift temp by 1 to process the next bit
    }
    
    // XOR num with mask to flip the bits and get the complement
    return num ^ mask;
    }
};