// MEDIUM - 198. House Robber
// SOLUTION - Dynamic Programming - We define our state being the best profit for robbing N houses
// Since this is a ovelapping problem, house_rob[n] will always be the best solution and when n < 0
// there is no house to be robbed, so value is 0.
// With this in mind, in order to rob a house we must consider two options:
// OPTION 1 - Rob the house N and then not to rob its adjacent (N - 1), only robbing the N - 2 as well
// OPTION 2 - Not rob the house N and only rob its adjacent (N-1)
// Then we compare which option is the best. By doing this we calcultate the best profit when robing up to N houses. 
// We save then this profit in house_rob[n] for further use


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;


class Solution {
    public:
        
        int steal(vector<int>& nums, vector<int>& house_rob, int house_num) {

            // If there is no house to be robbed, the value is 0
            if(house_num < 0) 
                return 0;
            // If the solution for this house_num has been calculated before, we reuse it
            if(house_rob[house_num] != -1) return house_rob[house_num];
            
            // Decide into our two options
            // Steal from the current house and the ones after the adjacent one
            int option1 = nums[house_num] + steal(nums, house_rob, house_num - 2);
            // Only steal the adjacent one
            int option2 = steal(nums, house_rob, house_num - 1);
            // Decide which one is the best option
            house_rob[house_num] = max(option1, option2);
            // Return this subsolution
            return house_rob[house_num];
        }

        int rob(vector<int>& nums) {
            
            int house_num = nums.size();

            vector<int> house_rob(house_num, -1);

            return steal(nums, house_rob, house_num - 1);
        }
    };