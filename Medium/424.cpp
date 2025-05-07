// MEDIUM - 424. Longest Repeating Character Replacement
// SOLUTION = SLIDING WINDOW. Use a hashmap to keep track of the letter with the biggest
// occurance when its is valid => It will only update when finding a bigger occurance that might
// contain a bigger sliding window
// It will slide the window to the right until find  a window that is valid.


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;


class Solution {
    public:
        int characterReplacement(string s, int k) {
            
            unordered_map<char, int> occurances;
            char currentChar;
            int currentSize = 0;
            int maxCount = 0;
            int maxSize = 0;
            int beginPointer = 0;

            for(int i = 0; i < s.length(); i++ ) {

                occurances[s[i]]++; // Add occurance in the letter s[i]
                maxCount = max(maxCount, occurances[s[i]]); // Checks if it is the biggest

                if((i - beginPointer + 1) - maxCount > k) { // Check if the window is valid
                   occurances[s[beginPointer]]--; // Decrease the occurance
                   beginPointer++; // Move to the left
                }

                maxSize = max(maxSize, i - beginPointer + 1);
            }

            return maxSize;
        }
    };