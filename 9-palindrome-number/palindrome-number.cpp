class Solution {
public:
    bool isPalindrome(int x) {
        // Step 1: Base cases
        // 1. Negative numbers are never palindromes (e.g., -121 reversed is 121-).
        // 2. Any number ending in 0 cannot be a palindrome unless the number is exactly 0.
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;

        // Step 2: Reverse the second half of the number
        // We know we've reached the middle when the remaining 'x' 
        // is less than or equal to our newly built 'revertedNumber'
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // Step 3: Check for equality
        // If the length of the number is even, x will exactly equal revertedNumber (e.g., 1221 -> x=12, rev=12).
        // If the length is odd, revertedNumber will have the middle digit. We can just divide by 10 to drop it.
        // (e.g., 12321 -> x=12, rev=123. rev/10 becomes 12).
        return x == revertedNumber || x == revertedNumber / 10;
    }
};