// MEDIUM - 22. Generate Parentheses
// SOLUTION - Backtracking - We call recusively the getCombinations functions which will be adding "(" or ")" to the string and it will stop when
// the string contains n "(" and n ")". However it will only add both of the elements if:
// 1- both of the elements has not excided the n amount in the string
// 2- ")" has to be always lower o equal to "(" (Well formed parenthesis) => We use open and close variables to keep track of it 

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <math.h>

using namespace std;

class Solution {
    public:
        // Global variable to store all the combinations
        vector<string> combinations;

        void getCombinations(int n, int open, int close, string formation) {
            
            // When both of the elemts reach n amount, so we found one solution
            if(open == n && close == n) {
                // Add this solution to the combination
                combinations.push_back(formation);
                return;
            }
            
            // If open has not exceded the n amount, then we can add one more
            if(open < n) getCombinations(n, open + 1, close, formation + "(");
            
            // If ")" is less than "(" so we are allowed to add one more
            if (close < open) getCombinations(n, open, close + 1, formation + ")");
            
        }

        vector<string> generateParenthesis(int n) {

            combinations.clear();
            getCombinations(n, 0, 0, "");
            return combinations;
        }
    };