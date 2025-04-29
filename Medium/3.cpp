// MEDIUM - 3. Longest Substring Without Repeating Characters

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            
            unordered_map<char, int> occurances;
            int maxLength = 0;
            int beginPointer = 0;
            int currentLength;

      

            for(int i = 0; i < s.length(); i++) {

                if(occurances.count(s[i])) 
                {
                    currentLength = i  - beginPointer;

                    if(currentLength > maxLength) {
                        maxLength = currentLength;
                    }
                     beginPointer = max(beginPointer, occurances[s[i]]);
                   
                }

                occurances[s[i]] = i + 1;
            }

            currentLength = s.length() - 1 - beginPointer; 
            
            if(currentLength > maxLength) maxLength = currentLength;

            return maxLength;
        }
    };