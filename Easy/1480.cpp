// EASY - 1480. Running Sum of 1d Array
// SOLUTION - Use a variable to store the sum of the previous numbers in the array

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        vector<int> runningSum(vector<int>& nums) {

            int size = nums.size();

            vector<int> runningSumVec(size); // Declare the vector with the sums
            int sum = 0; // Varibale to store the previous sum

            for(int i = 0; i < size; i++) {

                sum += nums[i]; // Add the current number to the sum
                runningSumVec[i] = sum; // Save the current sum in the position
            }

            return runningSumVec;
        }
    };