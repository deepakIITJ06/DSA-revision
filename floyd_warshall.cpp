#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

// all pair shortest path
// shortest path cycle -> (dist[i][i]!=0 --> means cycle) and take minimum out of all
// negative cycle --> if any of dist[i][i] is negative means negative cycle is there

class Solution {
public:
	void shortest_distance(vector<vector<int>>& matrix){
	    // Code here
        int n = matrix.size();
        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
                }
            }
        }
	}
};
