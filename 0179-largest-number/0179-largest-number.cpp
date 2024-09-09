class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Step 2: Sort strings based on custom comparator
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
            return a + b > b + a;  // Compare concatenated results
        });

        // Step 3: If the largest number is "0", return "0"
        if (strNums[0] == "0") return "0";

        // Step 4: Join the sorted strings into a single result
        string result;
        for (const string &str : strNums) {
            result += str;
        }

        return result;
    }
};