class Solution {
public:
    string fractionAddition(string expression) {
         int num = 0, denom = 1; // Initialize to 0/1

        regex rgx("([+-]?)([0-9]+)/([0-9]+)");
        auto it = sregex_iterator(expression.begin(), expression.end(), rgx);
        auto end = sregex_iterator();

        for (; it != end; ++it) {
            smatch match = *it;
            int sign = match[1].str() == "-" ? -1 : 1;
            int numerator = stoi(match[2].str());
            int denominator = stoi(match[3].str());
            
            numerator *= sign;

            num = num * denominator + numerator * denom;
            denom *= denominator;
            
            int gcd = __gcd(abs(num), denom);
            num /= gcd;
            denom /= gcd;
        }

        if (denom < 0) {
            num = -num;
            denom = -denom;
        }

        return to_string(num) + "/" + to_string(denom);
    }
};