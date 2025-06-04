// IMPOSSIBLE - DOES NOT MAKE SENSE, I CANT UNDERSTAND WHY THIS IS MEDIUM
// I HOPE I NEVER FACE THIS PROBLEM AGAIN GO F YOURSELF

// MEDIUM - 974 - Subarray Sums Divisible by K
// SOLUTION - Similar to 560 - But you keep track of how much is missing to the total
// sum be divided by K. 

#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
    public:
        int subarraysDivByK(vector<int>& nums, int k) {
            
            int counter = 0;
            unordered_map<int, int> rests;
            int currentSum = 0;

            rests[0] = 1; // If the rest is 0, so the current sum is already divided by k

            for(int i = 0; i < nums.size(); i++) {
                
                currentSum += nums[i]; // Add to current_Sum

                // Check of how much is missing to get in K
                int current_rest = ((currentSum % k) + k) % k;

                // If there is a fullfilling value, it means that there is a contiguous 
                // array that is divided by K
                if(rests.count(current_rest)) counter += rests[current_rest];

                rests[current_rest]++;
            }
            return counter;
        }
    };