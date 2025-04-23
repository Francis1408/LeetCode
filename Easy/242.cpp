
// EASY - 242. Valid Anagram
// SOLUTION = Using hashmap to save the number of occurances of each word
// THen in the end, comparing with both words contains the same ammount of letters
#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        bool isAnagram(string s, string t) {
            
            if(s.size() != t.size()) return false; // The string must be at the same size

            // Hashmaps to save the letters occurance
            std::unordered_map<char, int> letterS;
            std::unordered_map<char, int> letterT;

            for(int i = 0; i < s.size(); i++) { // Sweep both strings and grab their letters
                letterS[s[i]] += 1;
                letterT[t[i]] += 1;
            }

            // Compare if both maps got the same letter occurances 
            for (const auto& pair : letterS) {
                if(letterT[pair.first] != pair.second) return false; // if not
            }

            return true; // if yes
        }
    };