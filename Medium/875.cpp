// MEDIUM - 875. Koko Eating Bananas
// SOLUTION = BINARY SEARCH - We want the minimal speed so, we know that, in a worse case, koko
// needs to be at the speed of the max pile in order to eat all the bananas and, in the best case, 1 banana
// per hour => Then, we use binary search to pick a speed value in a imaginary array of speeds from
// [1 : maxPile]. We evaluate this speed then through the hole pile set. If Koko took more time than avaible,
// we must increase the speed avarage so: Beginning pointer = speed + 1; Otherwise, EndingPointer = speed - 1;

#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int min = 1; // Beginning pointer
            int max = 1; // Ending pointer
            int k; // Speed
            int result;

            // Get the biggest amount of bananas that koko can eat
            for(int i = 0; i < piles.size(); i++) {
                if(piles[i] > max) max = piles[i];
            }

            // Starts with max in case that the array size = 1
            result = max;

            int hoursLeft;

            while(min <= max) {

                k = floor((max + min)/2); // Take the avarage speed
                hoursLeft = h;

                // Evalueate the speed in the pile set
                for(int eatenPiles = 0; eatenPiles < piles.size(); eatenPiles++) {
                   
                    hoursLeft -= (piles[eatenPiles] + k -1)/ k;
                }

                if(hoursLeft < 0) { // It failed to eat all the bananas
                    min = k + 1; // Increase the avarage speed
                }
                else { // It succedeed so far, so we shall save the current speed
                    result = k; 
                    max = k - 1; // Decrease the avarage speed
                }

            }

            return result;
        }
    };