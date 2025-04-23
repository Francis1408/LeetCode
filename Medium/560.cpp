// MEDIUM - 560. Subarray Sum Equals K
#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;


class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            vector<int> window;
            int output = 0;
            int sum_of_elems = 0;
            for(int i = 0; i < nums.size(); i++) {

                sum_of_elems += nums[i];
                window.push_back(nums[i]);
                
                while(sum_of_elems >= k) {

                    if(sum_of_elems == k) output++;

                    sum_of_elems-= window[0];
                    window.erase(window.begin()); // Erase the oldest element from the list
                }

            }
            return output;
        }
    };