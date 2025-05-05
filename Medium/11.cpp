// MEDIUM - 11. Container With Most Water
// SOLUTION - The volume will always be limited to the lowest edge of the container
// So you calculate the currentVol, check if it is bigger and then move the pointer
// from the edge which is smaller, in order to attemp to find an edge which is bigger  
#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;


class Solution {
    public:
        int maxArea(vector<int>& height) {
            
            // Extremity pointers
            int left = 0; 
            int right = height.size() - 1;
            
            int maxVol = 0;
            int currentVol;
            int cWidth, cHeight;

            // While both pointers do not reach each other
            while(left != right) {

                // Calculates the containers volume
                cWidth = right - left;
                cHeight = min(height[left], height[right]);

                currentVol = cWidth * cHeight;
                maxVol = max(currentVol, maxVol); // Check if the current volume is bigger

                // Moves the pointer which contains the lowers value;
                if(height[left] < height[right]) left++;
                else right--;

            }

            // return max volume found
            return maxVol;
        }
    };