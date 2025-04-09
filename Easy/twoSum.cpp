//1. EASY - twoSum
// SOLUTION =  Saves te complements in a hashmap for future search
#include <iostream>
#include <vector>
#include <unordered_map>



class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        // IDEA: Iterates once in the array and takes what is left from each
        // subtraction from the target value and the index value and saves in memory;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (seen.count(complement)) { // Check if any of the complements from previous subtractions fullfils the current one
                return {seen[complement], i};
            }
            seen[nums[i]] = i; // Memory of what is left to complete with the idexes of each value
        }
        return {}; // no solution found
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result = sol.twoSum(nums, target);

    // Printing the result
    for (int i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}