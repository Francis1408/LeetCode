// MEDIUM - 452. Minimum Number of Arrows to Burst Balloons
// SOLUTION - Sort the ballons by end values. It means that lower values will not have the range to
// pop him plus another balloon. After it, we iterate through the sorted array and compare the end value with the
// beginning value of the follwing ballons. If the end is bigger or equal, it means that we can pop them together. 
// Otherwise, we take the end from the follwing one and repeat the process for the following ballons 


#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {

            int shots = 1;
            int maximalRange = 0;

            sort(points.begin(), points.end(), [](const vector<int>&a, const vector<int>&b){
                return a[1] < b[1]; // Sort based on the first element
            }); 

            maximalRange = points[0][1];

            for(int i = 0; i < points.size(); i++) {

                if(maximalRange < points[i][0]) {
                    shots++;
                    maximalRange = points[i][1];
                } 
            }
            return shots;
        }
    };