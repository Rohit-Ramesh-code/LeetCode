#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();
        
        // Start from the end of the array (the ones place) and move left
        for (int i = n - 1; i >= 0; --i) {
            // If the digit is less than 9, just add 1 and we are completely done!
            if (digits[i] < 9) {
                digits[i]++;
                return digits; 
            }
            
            // If the digit is 9, adding 1 makes it 10. 
            // So we set this digit to 0 and let the loop continue to carry the 1.
            digits[i] = 0;
        }
        
        // If we successfully get out of the loop, it means EVERY single digit was a 9.
        // For example: [9, 9, 9] became [0, 0, 0].
        // We just need to make it [1, 0, 0, 0].
        // Instead of shifting all elements to the right (which is slow), 
        // we can just add a 0 to the end and change the first digit to a 1!
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
    }
};