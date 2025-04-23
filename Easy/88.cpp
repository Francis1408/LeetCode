// EASY - 88. Merge Sorted Array

#include<iostream>
#include<vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            
            int current_index = 1;

           while(m != 0 && n != 0) {

            if(nums1[m-1] > nums2[n-1]) {
                nums1[nums1.size() - current_index] = nums1[m-1];
                current_index++;
                m--;
            }
            else if(nums1[m-1] < nums2[n-1]) {
                nums1[nums1.size() - current_index] = nums2[n-1];
                current_index++;
                n--;
            }
            else {
                nums1[nums1.size() - current_index] = nums1[m-1];
                current_index++;
                nums1[nums1.size() - current_index] = nums2[n-1];
                current_index++;
                n--;
                m--;
            }
           }
           if(m == 0) {
            for(int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
           }
        }
    };