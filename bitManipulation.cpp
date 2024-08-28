
class Solution {
public:
    void bitManipulation(int num, int i) {
        // Get the bit at the ith position (1-indexed)
        int getBit = (num >> (i - 1)) & 1;
        
        // Set the bit at the ith position
        int setBit = num | (1 << (i - 1));
        
        // Clear the bit at the ith position
        int clearBit = num & ~(1 << (i - 1));
        
        // Print the results of the three operations
        cout << getBit << " " << setBit << " " << clearBit;
    }
};
