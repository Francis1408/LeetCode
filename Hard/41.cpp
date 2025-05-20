// HARD -41. First Missing Positive
// SOLUTION - The Ideia is: If there are no negative and reapeating numbers, the values inside
// the array will be from [1:n], where n is the array size. 
// First - We mark the values the values which are outside this range. If at least one is marked
// it is guaranted that the sequence wont be fullfilled
// Second - Mark the values that are in the range => Move them to the beginning of the array  (to make the sequence)
// and assign a negative value to it => assign its value with the array position
// Third - Run another iteration checking if for a number that is not negative


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>
#include <math.h>

using namespace std;


class Solution {
    public:
        int firstMissingPositive(vector<int>& nums) {
            
            int n = nums.size();

            // First = Mark the values outside the range
            for(int i = 0; i < n; i++) {
                if(nums[i] > n || nums[i] < 1) nums[i] = n + 1;
            }

            for(int i = 0; i < n; i++) {
                int num = abs(nums[i]);

                if(num > n) continue;;// Outside the range

                num--;

                if(nums[num] > 0) // Checks if a value in that position is already marked
                    nums[num] = nums[num] * -1;
            }

            for(int i = 0; i < n; i++) {
                if(nums[i] > 0) return i + 1; // If the number in that position is not negative
                // it means that it's missing from the sequence
            }   

            // The sequence is complete
            return n + 1;
        }
    };
