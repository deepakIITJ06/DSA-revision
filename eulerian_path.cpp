class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;
        // Build the graph and track degrees
        for (auto& edge : pairs) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }
        // Find the starting node
        int start = pairs[0][0]; // Default start node
        for (auto& [node, outDeg] : outDegree) {
            if (outDeg > inDegree[node]) { // Out-degree > In-degree
                start = node;
                break;
            }
        }
        // Perform Hierholzer's algorithm to find Eulerian path
        stack<int> stk;
        vector<int> eulerPath;
        stk.push(start);
        while (!stk.empty()) {
            int curr = stk.top();
            if (!graph[curr].empty()) {
                int next = graph[curr].back();
                graph[curr].pop_back(); // Remove the edge
                stk.push(next);       // Move to the next node
            } else {
                eulerPath.push_back(curr); // Backtrack
                stk.pop();
            }
        }
        // Reverse to get the correct order
        reverse(eulerPath.begin(), eulerPath.end()); 
        // Construct the output as edge list
        vector<vector<int>> result;
        for (int i = 0; i < eulerPath.size() - 1; ++i) {
            result.push_back({eulerPath[i], eulerPath[i + 1]});
        }
        return result;
    }
};