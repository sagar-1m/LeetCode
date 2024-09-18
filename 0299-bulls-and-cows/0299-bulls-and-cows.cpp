class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int secret_count[10] = {0}, guess_count[10] = {0};

        // Step 1: Count bulls and record the frequency of non-bull characters
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;  // Matching character and position (bull)
            } else {
                // Count unmatched characters for cows calculation
                secret_count[secret[i] - '0']++;
                guess_count[guess[i] - '0']++;
            }
        }

        // Step 2: Count cows
        for (int i = 0; i < 10; ++i) {
            cows += min(secret_count[i], guess_count[i]);  // Matching non-bull characters
        }

        // Step 3: Format and return the result as "xAyB"
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
