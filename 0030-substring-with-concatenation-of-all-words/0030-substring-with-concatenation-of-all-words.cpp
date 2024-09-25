class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].length();       // Length of each word
        int total_words = words.size();         // Number of words
        int concat_len = total_words * word_len; // Total length of concatenated substring

        if (concat_len > s.length()) return result;

        // Frequency map for the words
        unordered_map<string, int> word_count;
        for (const string& word : words) {
            word_count[word]++;
        }

        // Sliding over the string with different starting positions
        for (int i = 0; i < word_len; ++i) {
            int left = i;
            unordered_map<string, int> window_count;
            int count = 0;

            // Sliding window
            for (int j = i; j <= s.length() - word_len; j += word_len) {
                string word = s.substr(j, word_len);
                // If the word is in our dictionary
                if (word_count.find(word) != word_count.end()) {
                    window_count[word]++;
                    count++;

                    // If the word appears more than its expected frequency, adjust the window
                    while (window_count[word] > word_count[word]) {
                        string left_word = s.substr(left, word_len);
                        window_count[left_word]--;
                        count--;
                        left += word_len;
                    }

                    // If we have matched all words in this window, record the start index
                    if (count == total_words) {
                        result.push_back(left);
                    }
                } else {
                    // If the word is not in words, reset the window
                    window_count.clear();
                    count = 0;
                    left = j + word_len;
                }
            }
        }

        return result;
    }
};
