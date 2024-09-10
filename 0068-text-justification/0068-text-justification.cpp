class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            // Step 1: Determine how many words fit into the current line
            int lineLength = words[i].length();
            int last = i + 1;
            
            while (last < n && lineLength + words[last].length() + (last - i) <= maxWidth) {
                lineLength += words[last].length();
                last++;
            }

            // Step 2: Create the line by justifying the words from index i to last - 1
            string line;
            int numWords = last - i;
            int numSpaces = maxWidth - lineLength;

            // Step 3: Check if it is the last line or a line with only one word
            if (last == n || numWords == 1) {
                // Left-justified line
                for (int j = i; j < last; ++j) {
                    line += words[j];
                    if (j < last - 1) line += " ";
                }
                // Add extra spaces at the end of the line
                line += string(maxWidth - line.length(), ' ');
            } else {
                // Fully justified line
                int spacesBetweenWords = numSpaces / (numWords - 1);
                int extraSpaces = numSpaces % (numWords - 1);

                for (int j = i; j < last - 1; ++j) {
                    line += words[j];
                    line += string(spacesBetweenWords + (j - i < extraSpaces ? 1 : 0), ' ');
                }
                // Add the last word without extra space
                line += words[last - 1];
            }

            result.push_back(line);
            i = last;  // Move to the next line
        }

        return result;
    }
};
