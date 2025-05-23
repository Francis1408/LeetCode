// MEDIUM - 200. Number of Islands
// SOLUTION - BFS and Recursion - We go through the matrix once, but when we find a position thats
// equal 1, so we check its adjacents (if it has). If one of its adjacents has 1 value, then we do the same
// for it recursively. We mark with # to inform that tile has already been visited. Every time that we get out of a
// recursion, we mark one island more.

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;

class Solution {
    public:

        void checkAdjacent(vector<vector<char>>& grid, int i, int j) {
            
            // Mark that space as visited
            grid[i][j] = '#';
            // Check the adjencies
            // TOP
            if(i-1 >= 0 && grid[i-1][j] == '1') checkAdjacent(grid, i-1, j);
            
            //BOTTOM
            if(i+1 < grid.size() && grid[i+1][j] == '1') checkAdjacent(grid, i+1, j);

            // LEFT
            if(j-1 >= 0 && grid[i][j-1] == '1') checkAdjacent(grid, i, j-1);

            // RIGHT
            if(j+1 < grid[i].size() && grid[i][j+1] == '1') checkAdjacent(grid, i, j+1);
        }
        int numIslands(vector<vector<char>>& grid) {
            
            int numIslands = 0;

            // Runs through the entire matrix
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[i].size(); j++) {

                    // If we found one space equals to 1, we start the recursion
                    // in order to check with the island is bigger
                    if(grid[i][j] == '1') {
                        numIslands++;
                        checkAdjacent(grid, i, j); // Recursion
                    }
                }
            }

            return numIslands;
        }
    };