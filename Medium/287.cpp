// MEDIUM - 287. Find the Duplicate Number
// Solution - Floyd's Algotithm - TBH I found extremely hard to understand. I will put a link below that
// explains the algho and good luck for me in the future in trying to understand this fucker
// https://cp-algorithms.com/others/tortoise_and_hare.html


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;


class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            
            // Phase 1: Find intersection point
            int tortoise = nums[0];
            int hare = nums[0];
            
            // Since there is a duplicate, so we will have a cycle in our path
            // Cycle = Two identical values will return to the same index
            do {
                tortoise = nums[tortoise];       // Move by 1 step
                hare = nums[nums[hare]];         // Move by 2 steps
            } while (tortoise != hare);
    
            // Phase 2: Find entrance to the cycle
            /*
            After L steps:

            Tortoise moves from start to entrance (L steps).

            Hare moves from k position in the cycle by L steps:

            k + L mod C steps — which brings it to the entrance if L ≡ (C - k) mod C.
            
            */
            
            tortoise = nums[0];
    
            while (tortoise != hare) {
                tortoise = nums[tortoise];       // Move by 1 step
                hare = nums[hare];               // Move by 1 step
            }
    
            return hare;  // or tortoise, both are the duplicate
        }
    };
    