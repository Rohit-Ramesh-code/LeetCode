#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        // Map each Roman numeral character to its integer value
        std::unordered_map<char, int> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int total = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            // If we are not at the last character, AND the current numeral is 
            // smaller than the next numeral, it's a subtractive combination.
            if (i < n - 1 && romanValues[s[i]] < romanValues[s[i + 1]]) {
                total -= romanValues[s[i]];
            } else {
                // Otherwise, it's standard additive notation.
                total += romanValues[s[i]];
            }
        }
        
        return total;
    }
};