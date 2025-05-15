// MEDIUM - 33. Search in Rotated Sorted Array
// SOLUTION - BINARY SEARCH - The ideia is: It does not matter if the array is rotated or not,
// it will always have at least one ascending half. If the ascending half is the first one (begin <= middle), we check
// if the number is between these values, otherwise, it must be in the other half.
// If begin > middle, it means that the ascending half is the second and we check if the number is between that interval,
// otherwise it must be in the first half

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <math.h>

using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int begin = 0; 
            int end = nums.size() - 1;

            while(begin <= end) {
                
                int middle = floor((begin + end)/2); // gets the middle value of the range

                if(nums[middle] == target) return middle; // if the number is in the middle return its idnex

                else {
                    if(nums[middle] >= nums[begin]) { // It means the the first half is ascending
                        if(target >= nums[begin] && target < nums[middle]) end = middle -1; // Check if the number is in range of this half
                        else begin = middle + 1; // Else, it must be on the second half
                    }
                    else { // It means that the second half is ascending
                        if(target > nums[middle] && target <= nums[end]) begin = middle + 1; // Check if the number is in range of this half
                        else end = middle -1; // Else, it must be on the first half
                    }
                }
            }

            return -1;
        }
    };
