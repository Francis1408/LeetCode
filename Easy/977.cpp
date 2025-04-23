// EASY - 977. Squares of a Sorted Array
// SOLUTION - Since is the values are squares => The edges of the vector might have
// the biggest numbers (most negative / most positive) => Take two pointers at the begin and at the end
// Compare the value of the numbers on each pointer => The bigger goes to the current last position of the sortedVector and its pointer
// moves to the next. Do this interation until they point to the same number (smallest one)

#include<iostream>
#include<vector>
#include <unordered_map>

using namespace std;


class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            
            int n = nums.size();
            vector<int> squaresSorted(n); // Sorted Vector with pre-defined size

            int begin = 0; // Begin pointer
            int end = n - 1; // End pointer
            int index = end;
            
            while(begin <= end) { // Until both pointers do not have the same index

                // Calculate the square root from the values
                int square1 = nums[begin] * nums[begin]; 
                int square2 = nums[end] * nums[end];

                // With the value from the left is bigger
                if(square1 > square2) {
                    // Place value to the current last position
                    squaresSorted[index--] = square1;
                    // Move begin pointer to the right
                    begin++;
                }
                // With the value from the right is bigger or equal
                else {
                    // Place value to the current last position
                    squaresSorted[index--] = square2;
                    // Move end pointer to the left
                    end--;
                }
            }
        
            return squaresSorted;
        }
    };