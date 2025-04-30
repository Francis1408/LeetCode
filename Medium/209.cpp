// MEDIUM - 209. Minimum Size Subarray Sum


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            
            int beginPointer;
            int endPointer;
            int totalSum = 0;
            int minimal = INT_MAX;

            for(endPointer = 0, beginPointer = 0; endPointer < nums.size(); endPointer++) {

                totalSum += nums[endPointer];
                
                 while(totalSum >= target ) {
                        
                     minimal = min(minimal, (endPointer - beginPointer) + 1);
                     totalSum -= nums[beginPointer];
                     beginPointer++;
                }

                
               
            }
            
            return (minimal == INT_MAX) ? 0 : minimal;
            
        }
    };