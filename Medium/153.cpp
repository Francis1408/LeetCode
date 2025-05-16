// MEDIUM - 153. Find Minimum in Rotated Sorted Array
// SOLUTION - SIMILAR TO 33 - Howver we will go through all the array slices to find a smaller number
// If middle > begin => it means that the fist half is a sequence and the smallest number in it is the begin
// if middle < begin => it means that the second half is a sequence and the smallest number in it is the middle
// after it we go to the begin/end pointer to the half that is not a sequence in order to find smaller values

#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
    public:
        int findMin(vector<int>& nums) {
            int begin = 0; 
            int end = nums.size() - 1;
            int minimal = 5000;

            while(begin <= end) {
                
                int middle = floor((begin + end)/2); // gets the middle value of the range

             
                if(nums[middle] >= nums[begin]) { // It means the the first half is ascending and begin is
                    // the smallest number in it

                    minimal = min(nums[begin], minimal); // Check if  begin is smaller
                    begin = middle + 1; //  navigates to the other half for smaller values
                }
                else { // It means that the second half is ascending and middle is the
                    // smallest number in it
                    minimal = min(nums[middle], minimal); // Check if middle is smaller
                    end = middle -1; //  navigates to the other half for smaller values
                }
            }

                return minimal;
            }

        };