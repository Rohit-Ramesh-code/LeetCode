#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // 'k' keeps track of where the next VALID element should go
        int k = 0; 

        for (int i = 0; i < nums.size(); ++i) {
            // If the current element is NOT the forbidden value
            if (nums[i] != val) {
                nums[k] = nums[i]; // Keep it by placing it at index 'k'
                k++;               // Move our placement marker forward
            }
        }

        // 'k' represents the number of elements that are not equal to 'val'
        return k;
    }
};