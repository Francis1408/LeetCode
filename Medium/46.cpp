// MEDIUM - 46. Permutations


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;


class Solution {
    public:
        vector<vector<int>> solutions;

        void backtracking(vector<int>& nums, int index) {

            if(nums.size() == index) {
                this->solutions.push_back(nums);
                return;
            } 
                       
            int aux;
            for( int i = index; i < nums.size(); i++) {
            aux = nums[index];
            nums[index] = nums[i];
            nums[i] = aux;
                
            backtracking(nums, index + 1);  
            
            // Swap back
            aux = nums[index];
            nums[index] = nums[i];
            nums[i] = aux;
                
            }
        }

        vector<vector<int>> permute(vector<int>& nums) {

            backtracking(nums, 0);
            return this-> solutions;
        }
    };