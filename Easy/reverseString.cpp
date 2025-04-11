// EASY - 344. Reverse String
// SOLUTION - Iterates half-size of the string, swaping the current first and current last 
#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        void reverseString(vector<char>& s) {
            
            char aux; // Aux variable to keep a value;
            for(int i = 0; i < (int)s.size()/2; i++) {
                aux = s[s.size() - 1 - i]; // Gets the current last
                s[s.size() - 1 - i] = s[i]; // Place the current first in the current last
                s[i] = aux; // Place the current last in the current first
            }
        }
    };