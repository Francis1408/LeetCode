// MEDIUM - 1143. Longest Common Subsequence
// SOLUTION - DYNAMIC PROGRAMMING - The ideia is build a matrix DP where will store all
// the longest sequence for each substring in text1 and text2.
// Example: "camelo" "aelzcamelo"
// DP[3][2] is the value of the longest substring between the strings "came" and "ael"
// THe relation between each subproblem is the following:
// DP[i][j] = DP[i - 1][j - 1] + 1 , if text1[i] == text2[j] 
// DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) , otherwise
// It means that when there is match, we will take the value from the subproblem when i and j
// were not part of the string and add + 1
// EXAMPLE: DP[2][4] = 1 + DP[1][3] => "ael" and "camel" got the value 3 which is 
// 1 + "ae" and "came" (2)
// When there is no match, we need to check if the element i or j, match with other previously elements, then return the biggest sequence value
// Our anwser is the last position of the matrix 

#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;


class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            
            int text1_size = text1.size();
            int text2_size = text2.size();

            // Initialize all elemets with 0 and place an extra column and row to avoid out of bounds problems
            vector<vector<int>>dp(text2_size + 1, vector<int>(text1_size + 1, 0));



            for(int i = 1; i < text2_size + 1; i++) {
                for(int j = 1; j < text1_size + 1; j++) {

                    // If the element i in the substring text2[0...i] matches 
                    // the element j in the substring text1[0...j]
                    if(text1[j - 1] == text2[i - 1]) {
                        // Take the sequence amount before those numbers and add 1, since
                        // we found another mathc
                        dp[i][j] = 1 + dp[i -1][j -1];
                    }
                    // If there is no match, we need to check if the element i or j, match with
                    // other previously elements, then return the biggest sequence value
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }

                }
            }



            return dp[text2_size][text1_size];

        }
    };