#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int count;  // To store the count of words that have this prefix
    
    TrieNode() {
        count = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    // Insert a word into the Trie and update prefix counts
    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->count++;  // Increment the count of this prefix
        }
    }
    
    // Get the sum of prefix scores for a given word
    int getPrefixScore(const string& word) {
        TrieNode* node = root;
        int score = 0;
        for (char c : word) {
            node = node->children[c];
            score += node->count;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        
        // Insert all words into the Trie
        for (const string& word : words) {
            trie.insert(word);
        }
        
        // Calculate the sum of prefix scores for each word
        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }
        
        return result;
    }
};
