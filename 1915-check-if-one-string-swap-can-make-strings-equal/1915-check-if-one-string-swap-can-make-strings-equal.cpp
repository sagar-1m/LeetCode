class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1 == s2) return true;

        std::vector<int> diff;
        int n = s1.length();

        // Find indices where s1 and s2 differ
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                diff.push_back(i);
            }
        }

        // If there are exactly 2 differing indices, check if swapping makes them equal
        return (diff.size() == 2 && 
                s1[diff[0]] == s2[diff[1]] && 
                s1[diff[1]] == s2[diff[0]]);
    }
};