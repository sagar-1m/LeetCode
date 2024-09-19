class Solution {
public:
    // A cache to store the results of already computed subexpressions
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        // If the expression has already been computed, return its result
        if (memo.count(expression)) return memo[expression];

        vector<int> result;
        
        // Loop over every character in the expression
        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];
            
            // If the character is an operator, split the expression
            if (c == '+' || c == '-' || c == '*') {
                // Recursively compute the left and right subexpressions
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results of the left and right parts
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            result.push_back(l + r);
                        } else if (c == '-') {
                            result.push_back(l - r);
                        } else if (c == '*') {
                            result.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If there are no operators, it's just a number, so return it as the result
        if (result.empty()) {
            result.push_back(stoi(expression));
        }

        // Cache the result for this expression
        memo[expression] = result;
        return result;
    }
};
