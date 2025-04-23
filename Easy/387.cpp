// EASY - 387. First Unique Character in a String

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int firstUniqChar(string s) {
            
            unordered_map<char, int> characters;

            for(int i = 0; i < s.length(); i++) {

                if(characters.count(s[i])) {
                    characters[s[i]] = -1;
                }
                else {
                    characters[s[i]] = i;
                }
            }

            int min = 1000000; 
            for(auto& x : characters) {
                if(x.second < min && x.second >= 0) 
                    min = x.second;
            }
            if(min ==  1000000) return -1;
            return min;
        }
    };