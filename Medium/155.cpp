// MEDIUM - 155. Min Stack
// SOLUTION = Since the structure is a stack, we dont need to care about the position of the minimal values
// Keep the small numbers in a different stack, which the top one will always be the min value
// When this is removed from the ordered stack, the next value on the satck will be the minimal value and the next one
// to be removed in the ordered stack
#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class MinStack {
    public:
        
        vector<int> orderStack; // Store the sequence
        vector<int> minStack; // Store the minimal values
        int minValue; 

        MinStack() {
            
        }
        
        void push(int val) {

            this->orderStack.push_back(val); // Adds element to the ordered stack


            if(this->minStack.size() == 0) { // if there is no elements in the minStack, the current val will be the minimun
                minValue = val;
                minStack.push_back(val);
            }
            else {
                if(minValue >= val) { // If it is lower or has the same value, it becomes the minValue 
                    minValue = val;  // And also the first potencial value to be removed lately 
                    minStack.push_back(val);
                } 
            }
        }
        
        void pop() {

            if(this->orderStack.size() != 0) {

                if(this->orderStack[orderStack.size() - 1] == minValue) { // If the minValue was been removed, the next one
                    minStack.pop_back();                                  // in the minStack will be the minValue

                    if(minStack.size() == 0) minValue = NULL; // Making sure that minValue does not take garbage
                    else minValue = minStack[minStack.size() -1];  
                }
                
                orderStack.pop_back(); // Remove from the ordered list
            }
                
        }
        
        int top() {
            if(this->orderStack.size() != 0 )
                return this->orderStack[orderStack.size() -1];

            else return NULL;
        }
        
        int getMin() {

            return minValue;
        }
    };
    
    /**
     * Your MinStack object will be instantiated and called as such:
     * MinStack* obj = new MinStack();
     * obj->push(val);
     * obj->pop();
     * int param_3 = obj->top();
     * int param_4 = obj->getMin();
     */