// MEDIUM - 347. Top K Frequent Elements
// SOLUTION - USING HEAP + PAIR + HASHMAP - Read the nums array and store the frequencies in a hashmap
// After it, add all the elements in the map inside a heap of pairs which is ordered by the first element of a pair
// So, make the first element of the pair being the num of occurances, in order to retrin the first k most frequent elements

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            
            unordered_map<int, int> frequencies; // Store the frequencies
            priority_queue<pair<int, int>> ranking; // Ordered by the first element of the pair
            vector<int> answer(k);

            // Read the first array and store the frequencies
            for(int i = 0; i < nums.size(); i++) {
                frequencies[nums[i]]++;
            }

            // Create the pair in the heap by assign the ordered number as the num of frequencies
            for(auto& x : frequencies) ranking.push(make_pair(x.second, x.first));

            // Return the K most frequent numbers in the heap
            for(int i = 0; i < k; i++) {
                answer[i] = ranking.top().second;
                ranking.pop();
            }

            return answer;
        }
    };