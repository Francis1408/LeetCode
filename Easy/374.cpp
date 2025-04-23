// EASY - 374. Guess Number Higher or Lower
// SOLUTION - Uses binary search to guess the number
// Starts at middle of the range of possible values and
// shrinks the possible range by half each interation, either for a lower end
// or top begin depeding on the target value (if it is higher o lower than our middle value inside the range)

#include<iostream>
#include<vector>
#include <unordered_map>

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

 class Solution {
    public:
        int guessNumber(int n) {
           int begin = 1; // lowest number
           int end = n; // highest number

           while(begin <= end) {

            int middle = begin + (end - begin)/2; // Avoids bit overflow
            
            // If the number is lower than our middle, so the number must be
            // in the lower half of our range
            if(guess(middle) == -1) end = middle -1; 

            // If the number is higher than our middle, so the number must be
            // in the top half of our range
            else if(guess(middle) == 1) begin = middle + 1;

            else return middle; // The number is our middle
           }

           return 0;
        }
    };