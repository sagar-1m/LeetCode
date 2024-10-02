class Solution {
public:
    // Trie Node definition
    struct TrieNode {
        bool isEnd;  // To check if a node represents the end of a root
        TrieNode* children[26];  // 26 letters of the alphabet
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; ++i)
                children[i] = nullptr;
        }
    };
    
    // Insert a word (root) into the Trie
    void insert(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;  // Mark the end of a root
    }
    
    // Find the shortest root for a given word
    string findRoot(TrieNode* root, const string& word) {
        TrieNode* node = root;
        string prefix;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr)
                break;
            node = node->children[idx];
            prefix += c;
            if (node->isEnd)  // If we've found a root, return it
                return prefix;
        }
        return word;  // If no root found, return the original word
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Step 1: Build the Trie from the dictionary
        TrieNode* trieRoot = new TrieNode();
        for (const string& root : dictionary) {
            insert(trieRoot, root);
        }
        
        // Step 2: Split the sentence into words
        istringstream ss(sentence);
        string word;
        string result;
        
        while (ss >> word) {
            // Step 3: Replace the word with its root (if exists)
            if (!result.empty()) result += " ";
            result += findRoot(trieRoot, word);
        }
        
        return result;
    }
};
