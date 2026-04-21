#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        // Base case: an empty array has 0 unique elements
        if (nums.empty()) return 0;

        // 'k' acts as our slow pointer. It keeps track of where 
        // the NEXT unique element should be placed.
        // We start at 1 because the very first element (index 0) 
        // is always unique by default.
        int k = 1; 

        // 'i' acts as our fast pointer, scanning through the array
        for (int i = 1; i < nums.size(); ++i) {
            // If the current number is DIFFERENT from the one right behind it,
            // we found a new unique number!
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i]; // Move the unique number to the front
                k++;               // Increment our unique element counter
            }
        }

        // 'k' now represents the total count of unique elements
        return k;
    }
};