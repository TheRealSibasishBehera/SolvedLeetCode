class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < times.size(); i++) {
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
            // adj[times[i][1]].push_back({times[i][0], times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, 1e9);

        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();

            for (auto adje : adj[node]) {
                int edgewt = adje.second;
                int edgenode = adje.first;
                if (dist[edgenode] > dis + edgewt) {
                    dist[edgenode] = dis + edgewt;
                    pq.push({dis + edgewt, edgenode});
                }
            }
        }

        // int maxi = 0;
int maxi = 0;
for (int i = 1; i <= n; i++) { // Start the loop from 1
    if (dist[i] == 1e9) {
        return -1;
    }
    maxi = max(dist[i], maxi);
}

        return maxi;
    }
};
