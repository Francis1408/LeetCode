// EASY - 35. Search Insert Position


#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            
            int begin = 0;
            int end = nums.size() - 1;
         

            while (begin <= end) {

                int middle = floor((end + begin)/2);

                if(nums[middle] == target) return middle;

                else if(nums[middle] < target) {
                    begin = middle + 1;
                } 

                else {
                    end = middle - 1; 
                }
            }

            return begin;
        }
    };