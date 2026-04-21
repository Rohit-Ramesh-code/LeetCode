#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int length = 0;
        int i = s.length() - 1; // Start at the very last character
        
        // Step 1: Skip any trailing spaces at the end of the string
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
        
        // Step 2: Count the characters of the actual last word
        // We stop when we hit another space OR the beginning of the string
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};