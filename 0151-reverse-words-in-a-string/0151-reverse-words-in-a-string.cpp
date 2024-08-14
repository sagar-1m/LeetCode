class Solution {
public:
    string reverseWords(string s) {
      istringstream iss(s);
        vector<string> words;
        string word;
        
        // Split the input string into words
        while (iss >> word) {
            words.push_back(word);
        }
        
        // Reverse the order of the words
        reverse(words.begin(), words.end());
        
        // Concatenate the words with a single space in between
        string result;
        for (const string& w : words) {
            result += w + " ";
        }
        
        // Remove the trailing space
        result.pop_back();
        
        return result;   
    }
};