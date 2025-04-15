// EASY - 704. Binary Search
// SOLUTION - Uses binary search to guess the number
// Starts at middle of the range of possible values and
// shrinks the possible range by half each interation, either for a lower end
// or top begin depeding on the target value (if it is higher o lower than our middle value inside the range)



#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int begin = 0; // lowest number
            int end = nums.size() - 1; // highest number

            while(begin <= end) {
                
                int middle = floor((begin + end)/2); // gets the middle value of the range

                // If the target is lower than our middle, so the number must be
                // in the lower half of our range
                if(nums[middle] < target) begin = middle + 1;

                // If the number is higher than our middle, so the number must be
                // in the top half of our range
                else if (nums[middle] > target) end = middle - 1;

                else return middle; // The number is our middle
            }

            return -1;

        }
    };