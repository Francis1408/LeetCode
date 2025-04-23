// EASY - 20. Valid Parentheses
// SOLUTION - Uses a stack since the closure order from the bracktes follows a FIFO 

#include<iostream>
#include<vector>

using namespace std;


class Solution {
    public:
        bool isValid(string s) {
            vector<char> stack; 

            for(char& bracket : s) {
                // Places the closure type in the stack if we read a oppening one
                // This is current the first one to be closed next
                if(bracket == '{')  stack.push_back('}');
                else if (bracket == '(')  stack.push_back(')');
                else if(bracket == '[')  stack.push_back(']');

                // If we read a close bracket
                else {
                    if(stack.size() == 0) return false; // If there is no oppened brackt, return false

                    else {
                        if(bracket == stack[stack.size() -1]) stack.pop_back(); // If the bracket type matches
                        else return false;
                    }
                }
            }
            if(stack.size() == 0) return true; // Make sure that in the end all the brackets has benn closed
            else return false;
        }
    };