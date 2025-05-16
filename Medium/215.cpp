// MEDIUM - 215. Kth Largest Element in an Array
// SOLUTION - Using Heap Data Stucture - It is a binary tree that keeps the min or maximum
// value at the root of it (in a array, the first position).
// IDEIA = Create a min-heap with size N, which the value on the root will be always the smallest one
// between the three. Thus, it is the kth current biggest number in the num array. When we iterate the array,
// we compare if there is a number which is bigger than the smallest number in the heap, which means that
// the root value is not the kth current biggest number in the nums array.
// In the end we will have a heap with the top 3 biggest numbers and then we return its root, since is
// a min heap

#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            
            
            vector<int> heap(k); // Takes the k first elements of the nums array 
            for(int i = 0; i < k; i++) {
                heap[i] = nums[i];
            }

            // Create the min heap with size K
            make_heap(heap.begin(), heap.end(), greater<int>()); // Creates a min-heap
            
            // Iterates through the 
            for(int i = k; i < nums.size(); i++) {
                if(nums[i] > heap.front()) { // If there is a element in the array that is bigger than the smallest value in the heap
                    pop_heap(heap.begin(), heap.end(), greater<int>()); // Move the root number to the back (last position) of the heap
                    heap.pop_back(); // Remove the last element of the heap
                    heap.push_back(nums[i]); // Include the new element to the heap
                    push_heap(heap.begin(), heap.end(), greater<int>()); // Sort the heap again
                }
            }
            
            return heap.front(); // Take the smallest number between the k biggest numbers
        }
    };