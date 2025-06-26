
// MEDIUM - 


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            
            int route_size = gas.size();
            int total_gas_avaiable = 0;

            vector<int> final_difference(route_size);

            for(int i = 0; i < route_size; i++) {

                final_difference[i] = gas[i] - cost[i];
                total_gas_avaiable += final_difference[i];
            }

            if(total_gas_avaiable < 0) return -1;


            int starting_point = 0;
            total_gas_avaiable = 0;

            for(int i = 0; i < route_size; i++) {
                
                total_gas_avaiable += final_difference[i];
                if(total_gas_avaiable < 0) {
                    starting_point = i + 1;
                    total_gas_avaiable = 0;
                }
            }
 
            return starting_point;
                

        }
    };