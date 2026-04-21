#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Base case: If the array is empty, there is no prefix
        if (strs.empty()) {
            return "";
        }

        // Sort the array of strings alphabetically
        std::sort(strs.begin(), strs.end());

        // Because the array is sorted, the strings that are the MOST 
        // different from each other are the first and the last strings.
        std::string first = strs.front();
        std::string last = strs.back();
        
        int matchIndex = 0;

        // Compare the first and last strings character by character
        while (matchIndex < first.size() && matchIndex < last.size() && first[matchIndex] == last[matchIndex]) {
            matchIndex++;
        }

        // Return the matching substring from the beginning up to the matchIndex
        return first.substr(0, matchIndex);
    }
};