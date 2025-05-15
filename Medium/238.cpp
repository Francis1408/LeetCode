// MEDIUM - 238. Product of Array Except Self 
// SOLUTION - Uses two vectors that store the prodvalue of the prefix and suffix of a certain
// index. We use the same loop to fulfill them, in which the suffix array is iterated backwards.
// In the end, we apply another loop to fill the awnser vector, by multiplying the suffix and preffix of
// each index


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int totalSize = nums.size();
            
            vector<int> preffix(totalSize); // preffix vector
            vector<int> suffix(totalSize); // suffix vector
            vector<int> answer(totalSize);

            int preffixProd = 1, suffixProd = 1; // Varible to store the current product of each preffix and suffix

            for(int i = 0; i < totalSize; i++) { // fills the preffix and suffix vectors

                preffix[i] =  preffixProd; // goes forward
                suffix[totalSize - 1 - i] = suffixProd; // goes backwards

                preffixProd*= nums[i]; // Multiplies the num value in the index with the current value of the preffix
                suffixProd*=  nums[totalSize - 1 - i];// Multiplies the num value in the index with the current value of the suffix
            }

            for(int i = 0; i < totalSize; i++) { // fills the answer
                answer[i] = preffix[i] * suffix[i];
            }

            return answer;
        }
    };
