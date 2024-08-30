#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i=1; i<=V-1; i++)
        {
            for(auto it:edges)
            {
                if(dist[it[0]]!=1e8 && dist[it[0]]+it[2] < dist[it[1]])
                {
                    dist[it[1]] = dist[it[0]]+it[2];
                }
            }
        }
        for(auto it:edges)
        {
            if(dist[it[0]]!=1e8 && dist[it[0]]+it[2] < dist[it[1]])
            {
                return {-1};
            }
        }
        return dist;
    }
};