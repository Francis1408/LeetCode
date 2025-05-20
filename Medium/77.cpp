// MEDIUM - 77. Combinations
// SOLUTION - IDENTICAL TO 46 - BACKTRACKING - The functions calls itself everytime after it add to the current array
// and successive number, until the current array reaches the maximun allowed size => When this
// happens, it means that the found a valid combination and we add to a global variable that stores the answers. 


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;


class Solution {
    public:

        vector<vector<int>> answer;

        void bactracking(int n ,int k, int index, vector<int> nums) {

            // If the array reaches the same size as the constraint
            // It means that we found a combination
            if(k == nums.size()) {
                this->answer.push_back(nums); // Store it
                return;
            }

            // We lock the index value within the [1:n] range in the certain position 
            // add it to the current array and calls the function again with sucessive methods
            for(int i = index; i <= n; i++) {
                nums.push_back(i);
                bactracking(n, k, i + 1, nums);
                nums.pop_back(); // It means that all the combinations with index value in that position are done
                // so we need to take it out and add an sucessive number
            }

        }

        vector<vector<int>> combine(int n, int k) {
            vector<int> nums;
            // Calls the funciton starting with a null vector and value 1
            bactracking(n, k, 1, nums);

            return answer;
        }
    };