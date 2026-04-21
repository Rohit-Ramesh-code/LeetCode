#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            // Calculate the middle index safely to prevent integer overflow
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid; // We found the target exactly
            } 
            else if (nums[mid] < target) {
                left = mid + 1; // Target must be in the right half
            } 
            else {
                right = mid - 1; // Target must be in the left half
            }
        }
        
        // If the loop finishes without returning, the target isn't in the array.
        // 'left' will naturally be sitting at the exact index where the target 
        // should be inserted to maintain the sorted order.
        return left;
    }
};