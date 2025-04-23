// EASY - 121. Best Time to Buy and Sell Stock
// SOLUTION = Always trying to find the minimum in the array
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int maxProfit;
            int min;
            min = prices[0];
            maxProfit = 0;
            for(int i = 0; i < prices.size(); i++) {
                if(prices[i] < min) min = prices[i]; // When sees a value that is lower than the current min, saves it
                // If the min is the current minimum, all the profits with the following values will be the best one.
                if(maxProfit < prices[i] - min) maxProfit = prices[i] - min; // If none of the following profits are better, you keep the previous one saved
            }
           return maxProfit; 
        }
    };