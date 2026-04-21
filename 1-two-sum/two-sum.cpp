#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // This map will store the numbers we've seen as the key, 
        // and their original index as the value.
        std::unordered_map<int, int> seenNumbers;

        for (int i = 0; i < nums.size(); ++i) {
            // Calculate the number we need to reach the target
            int complement = target - nums[i];

            // Check if we have already seen this required number
            if (seenNumbers.find(complement) != seenNumbers.end()) {
                // If we found it, return its stored index and our current index
                return {seenNumbers[complement], i};
            }

            // If we haven't seen the complement yet, add the current number 
            // and its index to our map for future reference
            seenNumbers[nums[i]] = i;
        }

        // The problem guarantees exactly one solution, so we should never hit this.
        // Returning an empty vector just to satisfy the compiler.
        return {};
    }
};