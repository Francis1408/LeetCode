// MEDIUM - 567. Permutation in String
// SOLUTION - SLIDING WINDOW - The window inside the s2 must be the same size of the s1. It begins with the endPointer(i)
// sliding foward the s2 and adding the amount of letters from inside the window in s2Amount.
// When window size == s1 size, it compares both vectors to see if the amount is equal. If it is, so there is a substring in s2
// that contains s1

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;


class Solution {
    public:
        bool checkInclusion(string s1, string s2) {

            if(s1.length() > s2.length()) return false; // s2 must be equal or bigger than s1

            // vectors to store how many times each letter in the alphabet appeared in the window and s1
            vector<int> s1Amount(26,0), s2Amount(26,0); 
            int beginPointer = 0;
            bool equal = false;

            for(char& c : s1) s1Amount[c - 'a']++; // gets the occurances in s1

            for(int i = 0; i < s2.length(); i++) {
                
                s2Amount[s2[i] - 'a']++; // sweeps the s2 string and registering the occurances

                if(i - beginPointer + 1 == s1.length()) { // when they are the same size
                    
                    if(s1Amount == s2Amount) return true; // check with they got the same occurances of letters

                    // If not, move the beginning pointer right once and discard its occurance
                    else {
                        s2Amount[s2[beginPointer] - 'a']--;
                        beginPointer++;
                    }
                }

            }
            // return false with we were not able to find a substring during the loop
            return false;
        }
    };