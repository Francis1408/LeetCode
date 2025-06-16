
// MEDIUM - 139. Word Break
// SOLUTION - Dynamic Programming - We use two pointers to check if in the range of j - (i - 1) 
// there is a substring in s that matches with a word in the dict. If does, we must check also if 
//  the starting position j is good to be broke, because, if j is in the middle of s, so the previous parts
// 0 ... j - 1 must be contained in a substing also. If all of this requirements match, so we mark in dp[i] that,
// the following letter after the substring is good to be broke. If s[s.length] is true, it means that the whole string
// can be broke into substring from the dict


#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            
            unordered_map<string, int> dict;
            vector<bool> dp(s.length() + 1, false); // One more space because dp[0] is considered empty string
            dp[0] = true; // Empty string is always breakable
        
            // transfer to hash for better manipulation
            for(string str : wordDict) {
                dict[str]++;
            }

            // Check if there is a suitable string between j and i - 1
            for(int i = 1; i <= s.length(); i++) {
                for(int j = 0; j < i; j++) {
                    string sub = s.substr(j, i - j);

                    // I there is a string and it is good to be breakable
                    if(dict.count(sub) && dp[j] == true) {

                        // Inform that the follwing letter is good to be breakable
                        dp[i] = true;
                        break;
                    }
                }
            }

            return dp[s.length()];

        }
    };