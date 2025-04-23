// EASY - 26. Remove Duplicates from Sorted Array
// SOLUTUTION - MIX OF THE PROBLEMS (283 & 387) - Use a hashmap to keep record of the repeated numbers
// The numbers which appear for the first time, are transfered to the beginning of the array based on
// the pointer => The k + 1 positions of the vector are the repeated numbers

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            
            unordered_map<int, int> occurances; // Keep the repeated numbers
            int k = 0; // Count of unique elements
            int beginPointer = 0; 
            int aux;

            for(int i = 0; i < nums.size(); i++) {

                if(!occurances.count(nums[i])) { // If the number hasnt been shown yet

                    occurances[nums[i]] = 1; // Save its occurance
                    
                    // Move its value to the beginning of the array
                    aux = nums[i];
                    nums[i] = nums[beginPointer];
                    nums[beginPointer] = aux;

                    k++; // Increment unique
                    beginPointer++; // Increment pointer, since the numbers from 0 to beginPointer - 1 are unique
                }
            }

            return k;
        }
    };