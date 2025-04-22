// EASY - 350. Intersection of Two Arrays II
// SOLUTION - Compare each element from  array1 to the entire array2. If the number exists
// in the array2, add it to the intersect and delete this number in the array2 after it
// BETTER SOLUTION - Use HashMap and save the amount of occurences of a certain number
// then compare it to the other array

#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
    public:
        vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
            
            vector<int> intersect;
            int aux;

            for(int i = 0; i < nums1.size(); i++) {
                for(int j = 0; j < nums2.size(); j++) {
                    
                    if(nums1[i] == nums2[j]) { // If there is an occurance in the array2
                        intersect.push_back(nums1[i]); // Add to the intersects
                        // Delete the matching number in array 2 by shifting it with the element in the last position
                        // And then poping it 
                        aux = nums2[nums2.size() - 1]; 
                        nums2[nums2.size() - 1] = nums2[j];
                        nums2[j] = aux;
                        nums2.pop_back();

                        break; // Dont need to check the rest of the array since we already found the matching element
                    }
                }
            }

            return intersect;
        }
    };