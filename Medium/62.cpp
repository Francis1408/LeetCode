//MEDIUM - 62. Unique Paths
// SOLUTION - Dynamic Programming - Since we can only move right or down, we do not have
//  the risk of returning to another position. So the num of paths to determined position is always
// gonna be the sum of num of paths from its top and left neighbor 

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;


class Solution {
    public:


        int uniquePaths(int m, int n) {
            
            // Initialize matrix with 0 values
            vector<vector<int>> matrix(m, vector<int>(n));

            // In the matrix corners, there is only one way to reach it
            for(int i = 0; i < m; i++) {matrix[i][0] = 1;}
            for (int j = 0; j < n; j++) {matrix[0][j] = 1;}

            int num_paths = 0;

            // The num of paths to reach each position is 
            // matrix[i-1][j] + matrix[i][j-1] 

            for(int i = 1; i < m; i++) {
                for(int j = 1; j < n; j++) {
                //                  TOP PART           LEFT PART
                    matrix[i][j] = matrix[i - 1][j] + matrix[i][j-1];
                }
            }

            // Return the bottom right value
            return matrix[m-1][n -1];

        }
    };