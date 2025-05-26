// MEDIUM - 547. Number of Provinces
// SOLUTION - BFS and Recursion - Since the matrix is a square matrix, we can simply use a visited vector
// in order to check with that node was already visited. If not, we apply a BFS on it to find all the other cities
// connected to it (which forms a province). After that, we continue check through the other cities.
// If one city after the BFS is still not visited, it means that it is not connected to any other city checked previously, so it must
// be another province  

#include<iostream>
#include<vector>
#include <unordered_map>
#include <numeric>
#include <limits.h>

using namespace std;

class Solution {
    public:

    // BFS method
        void bfs(vector<vector<int>>& isConnected, vector<int>& visited, int col) {
            
            // Mark the city as visited
            visited[col] = 1;

            // check in its line if it is connected to other city and then apply the bfs over it again
            for(int i = 0; i < isConnected[col].size(); i++) {
                if(isConnected[col][i] && !visited[i]) bfs(isConnected, visited, i);
            }

        }

        int findCircleNum(vector<vector<int>>& isConnected) {
            
            int numCities = isConnected.size();
            vector<int> visited(numCities, 0); 
            int provinces = 0;   

            // Go through evety city
            for(int i = 0; i < numCities; i++) {
                // If it is not visited yet, so it makes a new province
                if(!visited[i]) {
                    provinces++;
                    // Check if it is connected to another city 
                    bfs(isConnected, visited, i);
                }
            }
            
            return provinces;
        }
    };