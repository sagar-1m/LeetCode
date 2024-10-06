class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // Split sentences into words
        vector<string> words1 = splitSentence(sentence1);
        vector<string> words2 = splitSentence(sentence2);
        
        int n1 = words1.size();
        int n2 = words2.size();
        
        // Ensure words1 is the smaller or equal size array for simplicity
        if (n1 > n2) {
            swap(words1, words2);
            swap(n1, n2);
        }
        
        // Check prefix match
        int prefix = 0;
        while (prefix < n1 && words1[prefix] == words2[prefix]) {
            prefix++;
        }
        
        // Check suffix match
        int suffix = 0;
        while (suffix < n1 && words1[n1 - 1 - suffix] == words2[n2 - 1 - suffix]) {
            suffix++;
        }
        
        // Check if the non-matching part of words2 is between the prefix and suffix
        return (prefix + suffix) >= n1;
    }
    
private:
    // Helper function to split a sentence into words
    vector<string> splitSentence(const string& sentence) {
        istringstream iss(sentence);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        return words;
    }
};
