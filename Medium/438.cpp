// MEDIUM - 438. Find All Anagrams in a String
// SOLUTION  - SLIDING WINDOW - Same as 567 - However it saves the index of the 
// beginning pointer in an extra vector, when you find an anagram. Alsom the iteration only stops when 
// we reach the end of s
#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {

             // vectors to store how many times each letter in the alphabet appeared in s and p
            vector<char> currentAnagram(26, 0);
            vector<char> anagramP(26, 0);

            vector<int> indexes;
            int beginPonter = 0;

            for(char& c : p) anagramP[c - 'a']++; // gets the occurances in p

            for(int i = 0; i <  s.length(); i++) { // sweeps the s string and registering the occurances
 
                currentAnagram[s[i] - 'a']++;

                if(i - beginPonter + 1 >= p.length()) { // when they are the same size

                    if(currentAnagram == anagramP) indexes.push_back(beginPonter); // check with they got the same occurances of letters

                    currentAnagram[s[beginPonter] - 'a']--;
                    beginPonter++;
                }
            }
            return indexes;
        }
    };