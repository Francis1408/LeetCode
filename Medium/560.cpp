// MEDIUM - 560. Subarray Sum Equals K
// SOLUTION - Better explanation in this article: https://hashnode.com/post/subarray-sum-equals-k-ckod8z19l0bbofqs1god753rz
// The ideia is to keep track on the total sum on each position in a HashMap.
// For every position we do the following check: (totalSum - k) in order to see the difference needed to that
// current value reach the desirable K value. If we find this value in the hashMap, it means that from this position to the
// current one, we have a subarray which is contiguous and has the sum of k 
#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>

using namespace std;


class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {

            unordered_map<int, int> contiguous; // HashMap to keep the track on the total sum
            int totalSum = 0;
            int counter = 0;

            for(int i = 0; i < nums.size(); i++) {

                totalSum += nums[i]; // Is the sum equal to k
                if(totalSum == k ) counter++;

                if(contiguous.count(totalSum - k)) { //  Try to find a subarray that from it until our
                    // current position has the total value of K
                    counter += contiguous[totalSum -k]; 
                }

                contiguous[totalSum]++; // Add the current sum to the HashMap
            }

            return counter;
        }
    };