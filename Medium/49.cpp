// MEDIUM - 49. Group Anagrams
// SOLUTION - Use a data structure that saves all sort of letters group amount.
// If a string has the exact amount of letters in one of them, it is added to that group
// If not, we create a new group with that type of amount. In the end we add this group in the output

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;

class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            
            vector<vector<string>> groups; // Output
            vector<vector<int>> ocurrances; // Struct to saves all sort of letters group
            int found = -1; // flag to check with a string belongs to an already existing group

            for(int i = 0; i < strs.size(); i++) { // for each string the sting vector

                vector<int> amount(26,0); 

                for(char& c : strs[i]) amount[c - 'a']++; // take the amount of letters in the string

                for(int j = 0; j < ocurrances.size(); j++) { // Goes thorugh our data struct to see if the string belongs to a group

                    if(amount == ocurrances[j]) { // if true
                        // Added to this existing group
                        groups[j].push_back(strs[i]);
                        found = 1; // Inform that we already added this string
                        break;
                    }
                }

                if(found == -1) { // If the string was not added yet
                    // Create a new group for it
                    vector<string> newGroup;
                    // add this new group
                    newGroup.push_back(strs[i]); 
                    groups.push_back(newGroup);
                    ocurrances.push_back(amount);
                }

                found = -1;
            }

            return groups;
        }
    };