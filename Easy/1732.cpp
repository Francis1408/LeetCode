// EASY - 242. Valid Anagram
// SOLUTION -  Saves the highest altitude so fat in the maxAlt and keeps counting the 
// current Alt on each point. Saves new high if found

#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
    public:
        int largestAltitude(vector<int>& gain) {

            int maxAlt = 0; // Starts at 0
            int currentAlt = 0; // Gets the altitude on each point

            for(int i = 0; i < gain.size(); i++) {

                currentAlt += gain[i];

                if(currentAlt > maxAlt) { // if on that point the alt is bigger
                    maxAlt = currentAlt; // Take it as the highest altitude
                }

            }

            return maxAlt; //  return max
        }
    };