// MEDIUM - 739. Daily Temperatures
// SOLUTION - Using Stack structure - The content on the top of the stack will always be
// the index of the coldest temperature so far. Every time we read a new temperature in the temperatures array
// we compare it to the stack:
// IF IS COLDER: Add its index to the stack
// IF IS WARMER: Pop all the colder indexes in the stack until you find one that is not or the stack is empty
// Once you pop one element you compare its index with the current one (i). The difference will be the waiting days

#include<iostream>
#include<vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            
            int totalDays = temperatures.size();
            vector<int> awnser(totalDays, 0); // by default all the waiting times are 0
            stack<int> daysCount; // Stack

            for(int i = 0; i < totalDays; i++) {

                // When the current temperature is warmer
                while(!daysCount.empty() && temperatures[daysCount.top()] < temperatures[i]) {

                    // Pop the colder elements and register its waiting days
                    int top = daysCount.top();
                    daysCount.pop();
                    awnser[top] = i - top;  
                }
                
                // Add the temperature to the stack (if is colder or the stack is empty)
                daysCount.push(i);
            }

            return awnser;
        }
    };