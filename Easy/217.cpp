// EASY - 217. Contains Duplicate
// SOLUTION = Using hashmap to save duplicate occurances
#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            std::unordered_map<int, int> seen; // values that has been seen

            for (int i = 0; i < nums.size(); i++) { 
                if(seen.count(nums[i])) return true; // Search for duplicates
                else seen[nums[i]] = 1; // If it is the first occurance, marks it on the hashmap 
            }

            return false; // has found any duplicates
        }
    };