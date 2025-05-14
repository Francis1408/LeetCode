//EASY - 496. Next Greater Element I
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


class Solution {
    public:
        vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> stc;
            unordered_map<int, int> relations;
            vector<int> ans;

            for(int i = 0; i < nums2.size(); i++) {
                
                while(!stc.empty() && nums2[stc.top()] < nums2[i]) {
  
                    int top = stc.top();
                    stc.pop();
                    relations[nums2[top]] = nums2[i]; 
                }    
                
                stc.push(i);
            }

            for(int i = 0; i < nums1.size(); i++) {

                if(relations.count(nums1[i])) {
                    ans.push_back(relations[nums1[i]]);
                }
                else ans.push_back(-1);
            }

            return ans;
        }
    };