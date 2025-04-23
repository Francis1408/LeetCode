// EASY - 283. Move Zeroes


#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int beginPointer = 0;
            int aux;

            for(int i = 0; i < nums.size(); i++) {
                
                if(nums[i] != 0) {
                    aux = nums[i];
                    nums[i] = nums[beginPointer];
                    nums[beginPointer] = aux;
                    beginPointer++; 
                }
            
            }
        }
    };