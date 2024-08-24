class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for (int i = 0; i < s.length(); ++i) {
            char s_char = s[i];
            char t_char = t[i];

            // Check if there is already a mapping from s to t
            if (s_to_t.count(s_char) && s_to_t[s_char] != t_char) {
                return false;
            }

            // Check if there is already a mapping from t to s
            if (t_to_s.count(t_char) && t_to_s[t_char] != s_char) {
                return false;
            }

            // Create the mappings
            s_to_t[s_char] = t_char;
            t_to_s[t_char] = s_char;
        }

        return true;
    }
};