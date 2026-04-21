#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int m = haystack.length();
        int n = needle.length();
        
        // If the needle is longer than the haystack, it's impossible to find it
        if (n > m) return -1;
        
        // Slide a window of the needle's length across the haystack
        // We stop at (m - n) because there isn't enough room left in the 
        // haystack for the needle to fit after that point.
        for (int i = 0; i <= m - n; ++i) {
            int j = 0;
            
            // Check character by character within our current window
            while (j < n && haystack[i + j] == needle[j]) {
                j++;
            }
            
            // If our inner loop matched every character up to the needle's length
            if (j == n) {
                return i; // We found the start index!
            }
        }
        
        // If we checked every window and found nothing
        return -1;
    }
};