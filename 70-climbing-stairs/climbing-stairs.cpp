class Solution {
public:
    int climbStairs(int n) {
        // Base cases for the first two steps
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev2 = 1; // Ways to reach step (n-2)
        int prev1 = 2; // Ways to reach step (n-1)
        int current = 0;

        // Start calculating from step 3 up to n
        for (int i = 3; i <= n; ++i) {
            current = prev1 + prev2; // The ways to reach the current step
            prev2 = prev1;           // Move our 'n-2' pointer forward
            prev1 = current;         // Move our 'n-1' pointer forward
        }

        return current;
    }
};