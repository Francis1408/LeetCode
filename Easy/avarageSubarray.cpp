// EASY - 643. Maximum Average Subarray I
// SOLUTION = Using window algorithm, it gets the first K items from the array and makes the avarage
// Since subarray is contiguous, the next avarages will be the following item from the array minus the 
// item at the beginning of the window (oldest one)

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            vector<int> window;
            double output = -1e9; // Starts with a really low number
            int sum_elements = 0;

            if(nums.size() < k) return 0.0; // If there is no subarrays

            for(int i = 0; i < nums.size(); i++) {

                window.push_back(nums[i]);
                sum_elements += nums[i]; // Gets the sum of the current K elements
                
                if(window.size() == k) {

                    double aux;

                    aux = (double)sum_elements/k; // Apply avarege

                    if(aux > output) output = aux; // If the avarage is bigger

                    sum_elements -= window[0];
                    window.erase(window.begin()); // Erase the oldest element from the list
                }

            }
            return output;
        }
    };