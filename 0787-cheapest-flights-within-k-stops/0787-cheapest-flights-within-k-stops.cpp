class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<vector<int>> q;
        vector<int> dist(n, 1e9);

        q.push({0, src, 0});
        dist[src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            int node = it[1];
            int dis = it[0];
            int stops = it[2];

            q.pop();
            
            if (stops > k)
                continue;

            // if (node == dst && stops <= k + 1) {
                // return dis;
            // }

            for (auto adje : adj[node]) {
                int edgewt = adje.second;
                int edgenode = adje.first;
                if (stops <= k) {
                    if (dist[edgenode] > dis + edgewt && stops <= k + 1) {
                        dist[edgenode] = dis + edgewt;
                        q.push({dis + edgewt, edgenode, stops + 1});
                    }
                }
            }
        }
        
                if (dist[dst] == 1e9)
            return -1;
        return dist[dst];; // Return -1 if no valid path found
    }
};
