// EASY - 27. Remove Element
// SOLUTION - SIMILAR TO THE 283 - Use a pointer to lock the position of the first
// element with the value val. When you find an element which is different, you switch their
// positions and increase the pointer => You shove the numbers wiht value val to the end
// of the array

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {

            int beginPointer = 0; // Points to the first most left val in the array
            int aux;

            for(int i = 0; i < nums.size(); i++) {

                if(nums[i] != val) { // If there is one != to val
                    // shove the most left val to the right
                    aux = nums[i];
                    nums[i] = nums[beginPointer];
                    nums[beginPointer] = aux;

                    beginPointer++;
                  
                }
            }

            return beginPointer; // return the last index before the vals appear
        }
    };