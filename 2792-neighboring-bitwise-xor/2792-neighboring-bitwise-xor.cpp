class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
     int n = derived.size();
        
        // Start with an assumption for the first element
        int firstElement = derived[0];
        int original[100005];  // Define the array size as needed
        
        // Fill the original array using the properties of XOR
        original[0] = firstElement;
        for (int i = 1; i < n; i++) {
            original[i] = original[i-1] ^ derived[i-1];
        }
        
        // Verify if the calculated `original` matches the given `derived`
        for (int i = 0; i < n; i++) {
            if (original[i] ^ original[(i + 1) % n] != derived[i]) {
                return false;
            }
        }
        
        return true;
    }
};